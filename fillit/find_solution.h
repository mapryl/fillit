/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:26:16 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/26 13:40:44 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SOLUTION_H
# define FIND_SOLUTION_H

# include "field.h"
# include "tetr_list.h"

int		try_solve(t_field *field, const t_tetr_list *tetr_arr);
void	find_solution(const t_tetr_list *tetr_arr, int size_arr);

#endif
