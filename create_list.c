/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:25:03 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/25 18:34:16 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

s_tetr_list		*create_list(s_tetromin *head, s_tetr_list *next)
{
	s_tetr_list *tmp;

	tmp = (s_tetr_list*)malloc(sizeof(s_tetr_list));
	tmp->tetromin_data = *head;
	tmp->next = next;
	return (tmp);
}
