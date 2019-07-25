#include "ft_list.h"
#include <string.h>

void w_count(char* line, int *w_arr)
{
	//int w_arr[4] = { 0 };
	int i = 0;

	while (line[i])
	{
		if (line[i] == '#')
			w_arr[i % 5] = 1;
		i++;
	}
	//return w_arr;
}