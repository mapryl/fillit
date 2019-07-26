/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:21:15 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/26 17:02:32 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETROMINO_H
# define TETROMINO_H
# include "field.h"

typedef struct	s_tetromin
{
	char		*form;
	int			width;
	int			height;
}				t_tetromin;

t_tetromin		*cr_tet(char *tetromin, int figure_counter);
int				tetr_can_insert(const t_tetromin *tetromin, int y, int x,
		const t_field *field);
void			tetr_insert(const t_tetromin *tetromin, int y, int x,
		t_field *field);
void			tetr_erase(const t_tetromin *tetromin, int y, int x,
		t_field *field);
void			w_count(char *line, int *w_arr);
void			h_count(char *line, int *h_arr);

#endif
