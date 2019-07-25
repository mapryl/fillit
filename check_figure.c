/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:20 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/25 18:16:55 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		return_value(int touch)
{
	if (touch == 6 || touch == 8)
		return (1);
	else
		return (0);
}

int		check_figure(char *line)
{
	int touch;
	int hcount;
	int i;

	touch = 0;
	hcount = 0;
	i = 0;
	while (hcount < 4)
	{
		while (line[i] != '#')
			i++;
		if (line[i + 1] == '#')
			touch++;
		if (line[i - 1] == '#')
			touch++;
		if (line[i + 5] == '#')
			touch++;
		if (line[i - 5] == '#')
			touch++;
		hcount++;
		i++;
	}
	return (return_value(touch));
}
