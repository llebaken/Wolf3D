/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:33:54 by llebaken          #+#    #+#             */
/*   Updated: 2018/09/12 14:49:07 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_prepdda(t_main *m)
{
	m->w.map_x = (int)m->w.pos_x;
	m->w.map_y = (int)m->w.pos_y;
	m->w.deltadist_x = fabs(1 / m->w.raydir_x);
	m->w.deltadist_y = fabs(1 / m->w.raydir_y);
	m->w.hit = 0;
	if (m->w.raydir_x < 0)
	{
		m->w.step_x = -1;
		m->w.sidedist_x = (m->w.pos_x - m->w.map_x) * m->w.deltadist_x;
	}
	else
	{
		m->w.step_x = 1;
		m->w.sidedist_x = (m->w.map_x + 1.0 - m->w.pos_x) * m->w.deltadist_x;
	}
	if (m->w.raydir_y < 0)
	{
		m->w.step_y = -1;
		m->w.sidedist_y = (m->w.pos_y - m->w.map_y) * m->w.deltadist_y;
	}
	else
	{
		m->w.step_y = 1;
		m->w.sidedist_y = (m->w.map_y + 1.0 - m->w.pos_y) * m->w.deltadist_y;
	}
}

void	ft_checkwall(t_main *m)
{
	int testx;
	int testy;

	if (m->w.side == 0)
		m->w.perpwalldist = (m->w.map_x - m->w.pos_x +
				(1 - m->w.step_x) / 2) / m->w.raydir_x;
	else
		m->w.perpwalldist = (m->w.map_y - m->w.pos_y +
				(1 - m->w.step_y) / 2) / m->w.raydir_y;
	testx = (int)(m->w.pos_x + m->w.raydir_x * m->w.perpwalldist);
	testy = (int)(m->w.pos_y + m->w.raydir_y * m->w.perpwalldist);
	if (testx < 0 || testx > m->size_x || testy < 0 || testy > m->size_y)
	{
		m->w.hit = 1;
		m->w.perpwalldist = m->w.depth;
	}
	else
	{
		if (m->map[m->w.map_y][m->w.map_x] > 0)
			m->w.hit = 1;
	}
}

void	ft_dda(t_main *m)
{
	while (!m->w.hit && m->w.perpwalldist < m->w.depth)
	{
		if (m->w.sidedist_x < m->w.sidedist_y)
		{
			m->w.sidedist_x += m->w.deltadist_x;
			m->w.map_x += m->w.step_x;
			m->w.side = 0;
		}
		else
		{
			m->w.sidedist_y += m->w.deltadist_y;
			m->w.map_y += m->w.step_y;
			m->w.side = 1;
		}
		ft_checkwall(m);
	}
}

void	ft_raycasting(t_main *m)
{
	m->w.camera_x = 2 * m->w.x / (double)m->w.screen_w - 1;
	m->w.raydir_x = m->w.dir_x + m->w.plane_x * m->w.camera_x;
	m->w.raydir_y = m->w.dir_y + m->w.plane_y * m->w.camera_x;
	ft_prepdda(m);
	ft_dda(m);
}
