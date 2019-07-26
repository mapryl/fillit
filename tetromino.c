/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:47:56 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/26 14:18:36 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetromino.h"
#include <stdlib.h>
#include <string.h>

char		*to_letter(char *line, int w_arr[], int h_arr[])
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = (char *)malloc(sizeof(char) * w_arr[4] * h_arr[4] + 1);
	if (new_line == NULL)
		return (NULL);
	memset(new_line, '\0', w_arr[4] * h_arr[4] + 1);
	while (line[i])
	{
		if ((line[i] == '.' && w_arr[i % 5] == 1 && h_arr[i / 5] == 1)
			|| line[i] == '#')
		{
			new_line[j] = line[i];
			j++;
		}
		i++;
	}
	return (new_line);
}

t_tetromin	*cr_tet(char *tetromin, int figure_counter)
{
	t_tetromin *tetromin_head;
	int w_arr[5] = { 0 };
	int h_arr[5] = { 0 };
	int i;

	tetromin_head = (t_tetromin *)malloc(sizeof(t_tetromin));
	w_count(tetromin, w_arr);
	h_count(tetromin, h_arr);
	tetromin = to_letter(tetromin, w_arr, h_arr);
	i = 0;
	while (tetromin[i])
	{
		if (tetromin[i] == '#')
			tetromin[i] = 'A' + figure_counter;
		i++;
	}
	tetromin_head->form = tetromin;
	tetromin_head->width = w_arr[4];
	tetromin_head->height = h_arr[4];
	return (tetromin_head);
}

int			tetr_can_insert(const t_tetromin *tetromin, int y, int x, const t_field *field)
{
	if (field->size < x + tetromin->width || field->size < y + tetromin->height)
		return (0);
	for (int i = 0; i < tetromin->height; i++)
	{
		for (int j = 0; j < tetromin->width; j++)
		{
			if (field->field[i + y][j + x] !=
				'.' && tetromin->form[i * tetromin->width + j] != '.')
				return (0);
		}
	}
	return (1);
}

void		tetr_insert(const t_tetromin *tetromin, int y, int x, t_field *field)
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

void		tetr_erase(const t_tetromin *tetromin, int y, int x, t_field *field)
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
