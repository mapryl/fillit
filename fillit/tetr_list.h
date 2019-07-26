/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:27:31 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/26 14:15:27 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_LIST_H
# define TETR_LIST_H

# include "tetromino.h"

typedef struct			s_tetr_list
{
	t_tetromin			tetromin_data;
	struct s_tetr_list	*next;
}						t_tetr_list;

t_tetr_list				*create_list(t_tetromin *head, t_tetr_list *next);

#endif
