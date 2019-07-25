#ifndef FIND_SOLUTION_H
#define FIND_SOLUTION_H

#include "field.h"
#include "tetr_list.h"

int		try_solve(s_field* field, const s_tetr_list* tetr_arr);
void	find_solution(const s_tetr_list* tetr_arr, int size_arr);

#endif // !FIND_SOLUTION_H

