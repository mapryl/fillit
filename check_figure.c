#include <stdio.h> //Убрать вместе с printf при оформлении

int check_figure(char* line)
{
	int touch = 0; //количество касаний
	int hcount = 0; //количество проверенных шарпов
	int i = 0; //счетчик
	while (hcount < 4)
	{
		while (line[i] != '#')
			i++;
		if (line[i + 1] == '#')
			touch++;
		if (line[i - 1] == '#')
			touch++;
		if (line[i + 5] == '#')
			touch++;
		if (line[i - 5] == '#')
			touch++;
		hcount++;
		i++;
	}
	printf("Number of touches: %d\n", touch); //Вывод "касаний"
	if (touch == 6 || touch == 8)
		return (1);
	else
		return (0);
}