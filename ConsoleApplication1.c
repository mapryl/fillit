#include "ft_list.h"

char	*create_dot_str(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < size)
		{
			memcpy(str + i, ".", 2);
			i++;
		}
	}
	return (str);
}

void	field_create(s_field* field, int size)
{
	int		i;

	i = 0;
	field->field = (char**)malloc(sizeof(char*) * (size + 1));
	if (!(field->field))
		return ;
	while (i < size)
	{
		field->field[i] = create_dot_str(size);
		i++;
	}
	field->field[size] = "";
	field->size = size;
}

void	field_delete(s_field* field)
{
	int		i;

	i = 0;
	while (i < field->size)
	{
		free(field->field[i]);
		i++;
	}
	free(field->field);
}

void	field_resize(s_field* field, int size)
{
	field_delete(field);
	field_create(field, size);
}

int		tetr_can_insert(const s_tetromin *tetromin, int y, int x, const s_field *field)
{
	if (field->size < x + tetromin->width || field->size < y + tetromin->height)
		return (0);
	for (int i = 0; i < tetromin->height; i++)
	{
		for (int j = 0; j < tetromin->width; j++)
		{
			if (field->field[i + y][j + x] != '.' && tetromin->form[i * tetromin->width + j] != '.')
				return (0);
		}
	}
	return (1);
}

void tetr_insert(const s_tetromin* tetromin, int y, int x, s_field* field)
{
	char	symb;
	int		i;
	int		j;

	i = 0;
	while (i < tetromin->height)
	{
		j = 0;
		while (j < tetromin->width)
		{
			symb = tetromin->form[i * tetromin->width + j];
			if (symb != '.')
				field->field[i + y][j + x] = symb;
			j++;
		}
		i++;
	}
}

void	tetr_erase(const s_tetromin* tetromin, int y, int x, s_field* field)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetromin->height)
	{
		j = 0;
		while (j < tetromin->width)
		{
			if (tetromin->form[i * tetromin->width + j] != '.')
				field->field[i + y][j + x] = '.';
			j++;
		}
		i++;
	}
}

void	field_print(const s_field *field)
{
	int		i;
	int		j;

	i = 0;
	while (++i < field->size)
	{
		j = 0;
		while (++j < field->size)
			write(1, &field->field[i][j], 1);
		write(1, "\n", 1);
	}
}

int		try_solve(s_field *field, const s_tetr_list *tetr_arr)
{
	int		i;
	int		j;

	i = 0;
	if (tetr_arr == NULL)
		return (1);
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
		{
			if (tetr_can_insert(&tetr_arr->tetromin_data, i, j, field) == 1)
			{
				tetr_insert(&tetr_arr->tetromin_data, i, j, field);
				if (try_solve(field, tetr_arr->next) == 1)
					return (1);
				else
				{
					tetr_erase(&tetr_arr->tetromin_data, i, j, field);
					j++;
				}
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}

double	find_sqrt(int num)
{
	double	g;

	g = 1;
	while ((int)(g * g) != num)
		g = (g + num / g) / 2;
	return (g);
}

void	find_solution(const s_tetr_list *tetr_arr, int size_arr)
{
	s_field	field;
	int		size;

	size = (int)find_sqrt(size_arr * 4);
	field_create(&field, size);
	while (try_solve(&field, tetr_arr) == 0)
		field_resize(&field, ++size);
	field_print(&field);
}
