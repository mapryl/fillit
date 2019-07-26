#include "find_solution.h"
#include "field.h"
#include <stdlib.h>

int		try_solve(t_field * field, const t_tetr_list * tetr_arr)
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
					tetr_erase(&tetr_arr->tetromin_data, i, j++, field);
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

void	find_solution(const t_tetr_list * tetr_arr, int size_arr)
{
	t_field	field;
	int		size;

	size = (int)find_sqrt(size_arr * 4);
	field_create(&field, size);
	while (try_solve(&field, tetr_arr) == 0)
		field_resize(&field, ++size);
	field_print(&field);
}

