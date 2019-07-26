/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:37:04 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/26 12:43:56 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*create_dot_str(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < size)
			memcpy(str + i++, ".", 2);
	}
	return (str);
}

void	field_create(t_field *field, int size)
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

void	field_delete(t_field *field)
{
	int		i;

	i = 0;
	while (i < field->size)
		free(field->field[i++]);
	free(field->field);
}

void	field_resize(t_field *field, int size)
{
	field_delete(field);
	field_create(field, size);
}

void	field_print(const t_field *field)
{
	int		i;
	int		j;

	i = 0;
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
			write(1, &field->field[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}
