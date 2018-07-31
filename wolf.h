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
    double  cameraX;   //is the x-coordinate on the camera plane that the current x-coordinate of the screen represents && is either = -1(left side of screen) || 0 (center of screen) || 1 (right side of screen)
    double  rayDirX;
    double  rayDirY;
    int     mapX;      // is the x-coordinate of the square the ray is currently in
    int     mapY;      // is the y-coordinate of the square the ray is currently in 
    double  sideDistX; //initially the distance the ray has to travel from its start position to the first x-side
    double  sideDistY; //initially the distance the ray has to travel from its start position to the first -side 
    double  deltaDistX; //the distance the ray has to travel to go from 1 x-side to the next x-side
    double  deltaDistY; //the distance the ray has to travel to go from 1 y-side to the next y-side
    double  perpWallDist;
    int     stepX;  //Determines whether the dda formula should jump one square on the x-direction, postively or negatively  (either = 1 || -1)
    int     stepY;  //Determines whether the dda formula should jump one square on the y-direction, postively or negatively  (either = 1 || -1) 
    int     hit;    //was there a wall hit?
    int     side;   //was a NS or a EW wall hit? 
    int     lineHeight;
    int     drawStart;
    int     drawEnd;  
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
void    ft_raycasting(t_main *a);

#endif