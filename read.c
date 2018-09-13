/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:35:13 by llebaken          #+#    #+#             */
/*   Updated: 2018/09/12 13:55:41 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_allocate(t_main *m)
{
	int i;

	i = 0;
	if (m->size_x == 0 || m->size_y == 0)
	{
		ft_putstr("Error");
		exit(0);
	}
	m->map = (int **)malloc(sizeof(int *) * m->size_y);
	while (i < m->size_y)
	{
		m->map[i] = (int *)malloc(sizeof(int) * m->size_x);
		i++;
	}
}

void		ft_getxy(t_main *m)
{
	int		i;
	int		c;
	char	*line;
	char	**str;

	m->size_y = 0;
	i = 0;
	m->fd = open(m->file, O_RDONLY);
	while (get_next_line(m->fd, &line) > 0)
	{
		while (line[i] != '\0')
		{
			str = ft_strsplit(line, ' ');
			m->size_x = 0;
			c = 0;
			while (str[c++])
				m->size_x++;
			i++;
			ft_free2dchar(str);
		}
		free(line);
		m->size_y++;
	}
	close(m->fd);
}

void		ft_readmap(t_main *m)
{
	char	*str;
	char	**st;
	int		i;
	int		x;
	int		y;

	ft_getxy(m);
	ft_allocate(m);
	y = 0;
	m->fd = open(m->file, O_RDONLY);
	while (get_next_line(m->fd, &str) > 0)
	{
		x = 0;
		i = 0;
		st = ft_strsplit(str, ' ');
		while (st[i])
		{
			m->map[y][x] = ft_atoi(st[i]);
			i++;
			x++;
		}
		ft_free2dchar(st);
		free(str);
		y++;
	}
}
