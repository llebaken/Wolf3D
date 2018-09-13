/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:23:25 by llebaken          #+#    #+#             */
/*   Updated: 2018/09/13 14:39:33 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_boaders(t_main *m)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (x++ < m->size_x - 1)
		if (m->map[y][x] > 0)
			return (1);
	x = 0;
	y = m->size_y - 1;
	while (x++ < m->size_x - 1)
		if (m->map[y][x] > 0)
			return (1);
	y = 0;
	x = 0;
	while (y++ < m->size_y - 1)
		if (m->map[y][x] > 0)
			return (1);
	y = 0;
	x = m->size_x - 1;
	while (y++ < m->size_y - 1)
		if (m->map[y][x] > 0)
			return (1);
	return (-1);
}

void	ft_hasboarders(t_main *m)
{
	if (ft_boaders(m) == -1)
	{
		ft_putstr("Error");
		ft_free2dint(m->map, m->size_y);
		exit(0);
	}
}

void	ft_checkarray(t_main *m)
{
	int x;
	int y;

	y = 0;
	while (y < m->size_y)
	{
		x = 0;
		while (x < m->size_x)
		{
			if (m->map[y][x] < 0)
			{
				ft_putstr("Error Negative number found");
				ft_free2dint(m->map, m->size_y);
				exit(0);
			}
			x++;
		}
		y++;
	}
	ft_hasboarders(m);
}
