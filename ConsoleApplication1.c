#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <fcntl.h>
#include <math.h>
#include "ft_list.h"


char* create_dot_str(int size)
{
	char* str;
	
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return NULL;
	else
	{
		for (int i = 0; i < size; i++)
			memcpy(str + i, ".", 2);
	}
	return str;
}

void field_create(s_field* field, int size)
{
	/*
	Создание поля
	2 маллока
	Инициализация точками
	*/
	field->field = (char**)malloc(sizeof(char*) * (size + 1));
	if (!(field->field))
		return;
	for (int i = 0; i < size; i++)
	{
		field->field[i] = create_dot_str(size);
	}
	field->field[size] = "";
	field->size = size;
}
void field_delete(s_field* field)
{
	/*
	Стирание поля в for`е
	Для очищения перед расширением
	*/
	for (int i = 0; i < field->size; i++)
		free(field->field[i]);
	free(field->field);
}

void field_resize(s_field* field, int size)
{
	/*
	Вызов делета, потом креейт
	*/
	field_delete(field);
	field_create(field, size);
}

int tetr_can_insert(const s_tetromin *tetromin, int y, int x, const s_field *field)
{
	/*
	Проверяем можно ли вставить тетромин
	Передаем поле, тетромин и позицию где проверить возможность вставки
	Как только встретили конфликт - возвращаем 0
	Иначе 1
	*/
	if (field->size < x + tetromin->width || field->size < y + tetromin->height)
		return 0;
	for (int i = 0; i < tetromin->height; i++)
	{
		for (int j = 0; j < tetromin->width; j++)
		{
			if (field->field[i + y][j + x] != '.' && tetromin->form[i * tetromin->width + j] != '.')
				return 0;
		}
	}
	return 1;
}

void tetr_insert(const s_tetromin* tetromin, int y, int x, s_field* field)
{
	/*
	Вставляем тетромин
	*/
	char symb;

	for (int i = 0; i < tetromin->height; i++)
	{
		for (int j = 0; j < tetromin->width; j++)
		{
			symb = tetromin->form[i * tetromin->width + j];
			if (symb != '.')
				field->field[i + y][j + x] = symb;
		}
	}
}

void tetr_erase(const s_tetromin* tetromin, int y, int x, s_field* field)
{
	/*
	Удаляем тетромин
	*/
	for (int i = 0; i < tetromin->height; i++)
		for (int j = 0; j < tetromin->width; j++)
		{
			if (tetromin->form[i * tetromin->width + j] != '.')
				field->field[i + y][j + x] = '.';
			else
				continue;
		}
}

void field_print(const s_field *field)
{
	for (int i = 0; i < field->size; i++)
	{
		for (int j = 0; j < field->size; j++)
			printf("%c", field->field[i][j]);
		printf("\n");
	}
}

int try_solve(s_field *field, const s_tetr_list *tetr_arr)
{
	if (tetr_arr == NULL)
		return 1;
	for (int i = 0; i < field->size; i++)
	{
		for (int j = 0; j < field->size; j++)
		{
			if (tetr_can_insert(&tetr_arr->tetromin_data, i, j, field) == 1)
			{
				tetr_insert(&tetr_arr->tetromin_data, i, j, field);
				if (try_solve(field, tetr_arr->next) == 1)
					return 1;
				else
				{
					tetr_erase(&tetr_arr->tetromin_data, i, j, field);
					continue;
				}
			}
			else
				continue;
		}
	}
	return 0;
}

double find_sqrt(int num)
{
	double g = 1;
	while ((int)(g * g) != num)
	{
		g = (g + num / g) / 2;
	}
	return g;
}

void find_solution(const s_tetr_list *tetr_arr, int size_arr)
{
	s_field field;
	int size = find_sqrt(size_arr * 4);
	field_create(&field, size);
	while (try_solve(&field, tetr_arr) == 0)
	{
		field_resize(&field, ++size);
	}
	field_print(&field);
}

/*
В файнд солюшон задаем поле. Вызываем функцию трай солв. 
Если она возвращает один. Значит нашли решение, выводим это поле.
Если возвращает ноль, значит увеличиваем поле на единичку и снова вызываем трай солв.

Трай солв
Принимает на вход икс и игрек текущие (куда будет ставить фигурку)
и односвязный список тетроминов.
Проверяем если дошли до НулЪ, значит нашли решение и ретерн 1
Цикл по иск и игрек пока не вылезли за границы, пытаемся поставить текущую фигурку
Если не получается - прибавляем икс и игрек (не одновременно).
Если вышли за границы (некуда ставить) ретурним 0
Если поставили - вызываем сами себя от следующей фигуры и х + 1.

Смотрим результат от самовызова 
Если результат 1, то ретурн 1
Если результат 0, то продолжаем ставить себя (откатываем себя)

Создать структуру (односвязный список), которая будет хранить с_тетромино
*/
/*
int main(void)
{
//	printf("begin");
	//char a = 'a';
	//printf("%c", a);
	s_tetromin tetromin1 = { "AAAA", 1, 4 };
	s_tetromin tetromin2 = { "BBBB", 4, 1 };
	s_tetromin tetromin3 = { "CCC..C", 3, 2 };
	s_tetromin tetromin4 = { ".DDDD.", 3, 2 };
	s_tetromin tetromin5 = { "EEEE", 2, 2 };
	s_tetromin tetromin6 = { "FF..FF", 3, 2 };
	s_tetromin tetromin7 = { "GG.G.G", 2, 3 };
	s_tetromin tetromin8 = { "HHH.H.", 3, 2 };
	
	s_tetr_arr tetr8 = { tetromin8, NULL };
	s_tetr_arr tetr7 = { tetromin7, &tetr8 };
	s_tetr_arr tetr6 = { tetromin6, &tetr7 };
	s_tetr_arr tetr5 = { tetromin5, &tetr6 };
	s_tetr_arr tetr4 = { tetromin4, &tetr5 };
	s_tetr_arr tetr3 = { tetromin3, &tetr4 };
	s_tetr_arr tetr2 = { tetromin2, &tetr3 };
	s_tetr_arr tetr1 = { tetromin1, &tetr2 };
	find_solution(&tetr1, 8);

	return 0;
}
*/