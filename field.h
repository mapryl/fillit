/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:39:50 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/26 12:55:51 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_H
# define FIELD_H

typedef struct
{
	int		size;
	char	**field;
}			t_field;

void		field_create(t_field *field, int size);
void		field_delete(t_field *field);
void		field_resize(t_field *field, int size);
void		field_print(const t_field *field);

#endif
