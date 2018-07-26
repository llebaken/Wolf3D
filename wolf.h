#ifndef WOLF_H
# define WOLF_H

# include "includes/SDL2/SDL.h"
# include "includes/libft/libft.h"
# include "includes/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_wolf
{
    int     quit;
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    double  time;
    double  oldtime;
    int     x;
    int     y;
    int     w;
    int     h;
}               t_wolf;

typedef struct  s_sdl
{
    SDL_Window      *win;
    SDL_Renderer    *ren;
}               t_sdl;

typedef struct  s_main
{
    int     **map;
    int     x;
    int     y;
    int     fd;
    char    *file;
    t_wolf  w;
    t_sdl   s;
}               t_main;

void    ft_readmap(t_main *m);

#endif