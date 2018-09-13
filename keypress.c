/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:32:06 by llebaken          #+#    #+#             */
/*   Updated: 2018/09/12 14:41:14 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_up(t_main *m)
{
	if (m->map[(int)m->w.pos_y]
	[(int)(m->w.pos_x + m->w.dir_x * m->w.movespeed)] == 0)
		m->w.pos_x += m->w.dir_x * m->w.movespeed;
	if (m->map[(int)(m->w.pos_y + m->w.dir_y * m->w.movespeed)]
	[(int)m->w.pos_x] == 0)
		m->w.pos_y += m->w.dir_y * m->w.movespeed;
}

void	ft_down(t_main *m)
{
	if (m->map[(int)m->w.pos_y]
	[(int)(m->w.pos_x - m->w.dir_x * m->w.movespeed)] == 0)
		m->w.pos_x -= m->w.dir_x * m->w.movespeed;
	if (m->map[(int)(m->w.pos_y - m->w.dir_y * m->w.movespeed)]
	[(int)m->w.pos_x] == 0)
		m->w.pos_y -= m->w.dir_y * m->w.movespeed;
}

void	ft_right(t_main *m)
{
	m->w.olddir_x = m->w.dir_x;
	m->w.dir_x = m->w.dir_x * cos(-m->w.rotspeed) -
		m->w.dir_y * sin(-m->w.rotspeed);
	m->w.dir_y = m->w.olddir_x * sin(-m->w.rotspeed) +
		m->w.dir_y * cos(-m->w.rotspeed);
	m->w.oldplane_x = m->w.plane_x;
	m->w.plane_x = m->w.plane_x * cos(-m->w.rotspeed) -
		m->w.plane_y * sin(-m->w.rotspeed);
	m->w.plane_y = m->w.oldplane_x * sin(-m->w.rotspeed) +
		m->w.plane_y * cos(-m->w.rotspeed);
}

void	ft_left(t_main *m)
{
	m->w.olddir_x = m->w.dir_x;
	m->w.dir_x = m->w.dir_x * cos(m->w.rotspeed) -
		m->w.dir_y * sin(m->w.rotspeed);
	m->w.dir_y = m->w.olddir_x * sin(m->w.rotspeed) +
		m->w.dir_y * cos(m->w.rotspeed);
	m->w.oldplane_x = m->w.plane_x;
	m->w.plane_x = m->w.plane_x * cos(m->w.rotspeed) -
		m->w.plane_y * sin(m->w.rotspeed);
	m->w.plane_y = m->w.oldplane_x * sin(m->w.rotspeed) +
		m->w.plane_y * cos(m->w.rotspeed);
}

void	ft_keypress(t_main *m)
{
	m->w.x = 0;
	m->w.oldtime = m->w.time;
	m->w.time = SDL_GetTicks();
	m->w.frametime = (m->w.time - m->w.oldtime) / 1000.0;
	SDL_RenderPresent(m->s.ren);
	SDL_RenderClear(m->s.ren);
	m->w.movespeed = m->w.frametime * 5.0;
	m->w.rotspeed = m->w.frametime * 3.0;
	while (SDL_PollEvent(&m->s.event))
	{
		if (m->s.event.type == SDL_QUIT ||
				m->s.event.key.keysym.sym == SDLK_ESCAPE)
			m->quit = 1;
		if (m->s.event.key.keysym.sym == SDLK_UP)
			ft_up(m);
		if (m->s.event.key.keysym.sym == SDLK_DOWN)
			ft_down(m);
		if (m->s.event.key.keysym.sym == SDLK_RIGHT)
			ft_right(m);
		if (m->s.event.key.keysym.sym == SDLK_LEFT)
			ft_left(m);
	}
}
