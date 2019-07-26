/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_h_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:12:06 by mapryl            #+#    #+#             */
/*   Updated: 2019/07/26 17:12:16 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	w_count(char* line, int* w_arr)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
			w_arr[i % 5] = 1;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (w_arr[i] == 1)
			w_arr[4]++;
		i++;
	}
}

void	h_count(char* line, int* h_arr)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
			h_arr[i / 5] = 1;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (h_arr[i] == 1)
			h_arr[4]++;
		i++;
	}
}
