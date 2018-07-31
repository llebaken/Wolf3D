#include "wolf.h"

void    ft_stepNsideDest(t_main *a)
{
    //calculate step and initial sideDist
    if (a->w.rayDirX < 0)
    {
        a->w.stepX = -1;
        a->w.sideDistX = (a->w.posX - a->w.mapX) * a->w.deltaDistX;
    }
    else
    {
        a->w.stepX = 1;
        a->w.sideDistX = (a->w.mapX + 1.0 - a->w.posX ) * a->w.deltaDistX;
    }
    if (a->w.rayDirY < 0)
    {
        a->w.stepY = -1;
        a->w.sideDistY = (a->w.posY - a->w.mapY) * a->w.deltaDistY;
    }
    else
    {
        a->w.stepX = 1;
        a->w.sideDistY = (a->w.mapY + 1.0 - a->w.posY ) * a->w.deltaDistY;
    }
}

void    ft_prepdda(t_main *a)
{
    a->w.mapX = (int)a->w.posX;
    a->w.mapY = (int)a->w.posY;
    a->w.deltaDistX = sqrt(1 + (a->w.rayDirY * a->w.rayDirY) / (a->w.rayDirX * a->w.rayDirX)); //std::abs(1 / rayDirX);
    a->w.deltaDistY = sqrt(1 + (a->w.rayDirX * a->w.rayDirX) / (a->w.rayDirY * a->w.rayDirY)); //std::abs(1 / rayDirY);
    a->w.hit = 0;
    ft_stepNsideDest(a);
}

void    ft_dda(t_main *a)
{
    while(a->w.hit == 0)
    {
        if (a->w.sideDistX < a->w.sideDistY)
        {
            a->w.sideDistX += a->w.deltaDistX;
            a->w.mapX += a->w.stepX;
            a->w.side = 0;
        }
        else
        {
            a->w.sideDistY += a->w.deltaDistY;
            a->w.mapY += a->w.stepY;
            a->w.side = 1;
        }
        if (a->map[a->w.mapX][a->w.mapY] > 0)
            a->w.hit = 1;
    }
}

void    ft_prepdraw(t_main *a)
{
    a->w.lineHeight = (int)(a->w.h / a->w.perpWallDist);
    a->w.drawStart = -a->w.lineHeight / 2 + a->w.h / 2;
    if (a->w.drawStart < 0)
        a->w.drawStart = 0;
    a->w.drawEnd = a->w.lineHeight / 2 + a->w.h / 2;
    if (a->w.drawEnd >= a->w.h)
        a->w.drawStart = a->w.h - 1;
}

void    ft_raycasting(t_main *a)
{
    //calculate ray position and direction
    a->w.cameraX = 2 * a->w.x / (double)a->w.w - 1; //x-coordinate in camera space
    a->w.rayDirX = a->w.dirX + a->w.planeX * a->w.cameraX;
    a->w.rayDirY = a->w.dirY + a->w.planeY * a->w.cameraX;
    ft_prepdda(a);
    ft_dda(a);
    //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
    if (a->w.side == 0)
        a->w.perpWallDist = (a->w.mapX - a->w.posX + (1 - a->w.stepX) / 2) / a->w.rayDirX;
    else
        a->w.perpWallDist = (a->w.mapY - a->w.posY + (1 - a->w.stepY) / 2) / a->w.rayDirY;
    ft_prepdraw(a);
}