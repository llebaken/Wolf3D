/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:35:49 by llebaken          #+#    #+#             */
/*   Updated: 2018/09/12 14:36:30 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "includes/SDL2/SDL.h"
# include "includes/libft/libft.h"
# include "includes/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_wolf
{
	int				screen_w;
	int				screen_h;
	int				x;
	int				y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			oldtime;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			olddir_x;
	double			oldplane_x;
	int				ceiling;
	int				floor;
	double			depth;
}					t_wolf;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_main
{
	int				**map;
	int				size_x;
	int				size_y;
	int				fd;
	char			*file;
	int				quit;
	t_wolf			w;
	t_sdl			s;
}					t_main;

void				ft_readmap(t_main *m);
void				ft_raycasting(t_main *m);
void				ft_drawmap(t_main *m);
void				ft_keypress(t_main *m);

#endif
