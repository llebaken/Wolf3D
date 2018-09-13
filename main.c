/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:33:09 by llebaken          #+#    #+#             */
/*   Updated: 2018/09/12 14:42:19 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_initsdl(t_main *m)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m->s.win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, m->w.screen_w, m->w.screen_h, 0);
	m->s.ren = SDL_CreateRenderer(m->s.win, -1, SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m->s.ren, 0, 0, 0, 255);
	SDL_RenderPresent(m->s.ren);
	SDL_RenderClear(m->s.ren);
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
}

void	ft_init(t_main *m)
{
	m->w.screen_w = 512;
	m->w.screen_h = 384;
	m->w.pos_x = m->size_x / 2;
	m->w.pos_y = m->size_y / 2;
	m->w.dir_x = -1;
	m->w.dir_y = 0;
	m->w.plane_x = 0;
	m->w.plane_y = 0.66;
	m->w.time = 0;
	m->w.oldtime = 0;
	m->w.x = 0;
	if (m->size_x > m->size_y)
		m->w.depth = m->size_x;
	else
		m->w.depth = m->size_y;
	m->quit = 0;
}

void	ft_wolf(t_main *m)
{
	ft_raycasting(m);
	ft_drawmap(m);
}

int		main(int ac, char **av)
{
	t_main m;

	if ((ac != 2) || (!ft_strstr(av[1], ".w3d")))
		ft_putstr("Please add .w3d file\n");
	else
	{
		m.file = av[1];
		ft_readmap(&m);
		ft_checkarray(&m);
		ft_init(&m);
		ft_initsdl(&m);
		while (!m.quit)
		{
			while (m.w.x++ < m.w.screen_w)
				ft_wolf(&m);
			ft_keypress(&m);
		}
		SDL_DestroyWindow(m.s.win);
		SDL_Quit();
		ft_free2dint(m.map, m.size_y);
	}
	return (0);
}
