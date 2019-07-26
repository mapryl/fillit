/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:11:33 by mapryl            #+#    #+#             */
/*   Updated: 2019/07/26 17:11:36 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H
# define BUFF_SIZE 21

int		check_file(char *line);
int		check_figure(char *line);
int		setup(char **argv);

#endif
