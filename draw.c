/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:30:40 by llebaken          #+#    #+#             */
/*   Updated: 2018/09/12 14:48:17 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_color(t_main *m)
{
	if (m->w.side == 1)
	{
		if (m->w.step_y == -1)
			SDL_SetRenderDrawColor(m->s.ren, 255, 0, 0, 255);
		else
			SDL_SetRenderDrawColor(m->s.ren, 0, 255, 0, 255);
	}
	else
	{
		if (m->w.step_x == -1)
			SDL_SetRenderDrawColor(m->s.ren, 0, 0, 255, 255);
		else
			SDL_SetRenderDrawColor(m->s.ren, 255, 0, 255, 255);
	}
}

void	ft_draw(t_main *m)
{
	if (m->w.y <= m->w.ceiling)
	{
		SDL_SetRenderDrawColor(m->s.ren, 135, 206, 250, 1);
		SDL_RenderDrawPoint(m->s.ren, m->w.x, m->w.y);
	}
	else if (m->w.y > m->w.ceiling && m->w.y <= m->w.floor)
	{
		ft_color(m);
		SDL_RenderDrawPoint(m->s.ren, m->w.x, m->w.y);
	}
	else
	{
		SDL_SetRenderDrawColor(m->s.ren, 222, 184, 135, 222);
		SDL_RenderDrawPoint(m->s.ren, m->w.x, m->w.y);
	}
}

void	ft_drawmap(t_main *m)
{
	if (m->w.side == 0)
		m->w.perpwalldist = (m->w.map_x - m->w.pos_x +
				(1 - m->w.step_x) / 2) / m->w.raydir_x;
	else
		m->w.perpwalldist = (m->w.map_y - m->w.pos_y +
				(1 - m->w.step_y) / 2) / m->w.raydir_y;
	m->w.ceiling = (float)(m->w.screen_h / 2.0) - m->w.screen_h
		/ ((float)m->w.perpwalldist);
	m->w.floor = m->w.screen_h - m->w.ceiling;
	m->w.y = 0;
	while (m->w.y < m->w.screen_h)
	{
		ft_draw(m);
		m->w.y++;
	}
}
