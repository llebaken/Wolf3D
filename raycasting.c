void    ft_stepNsideDest(t_main *a)
{
    //calculate step and initial sideDist
    if (a.w->rayDirX < 0)
    {
        a.w->stepX = -1;
        a.w->sideDistX = (a.w->posX - a.w->mapX) * a.w->deltaDistX;
    }
    else
    {
        a.w->stepX = 1;
        a.w->sideDistX = (a.w->mapX + 1.0 - a.w->posX ) * a.w->deltaDistX;
    }
    if (a.w->rayDirY < 0)
    {
        a.w->stepY = -1;
        a.w->sideDistY = (a.w->posY - a.w->mapY) * a.w->deltaDistY;
    }
    else
    {
        a.w->stepX = 1;
        a.w->sideDistY = (a.w->mapY + 1.0 - a.w->posY ) * a.w->deltaDistY;
    }
}

void    ft_prepdda(t_main *a)
{
    a.w->mapX = (int)posX;
    a.w->mapY = (int)posY;
    a.w->deltaDistX = sqrt(1 + (a.w->rayDirY * a.w->rayDirY) / (a.w->rayDirX * a.w->rayDirX)) //std::abs(1 / rayDirX);
    a.w->deltaDistY = sqrt(1 + (a.w->rayDirX * a.w->rayDirX) / (a.w->rayDirY * a.w->rayDirY)) //std::abs(1 / rayDirY);
    a.w->hit = 0;
    ft_stepNsideDest(a);
}

void    ft_raycasting(t_main *a)
{
    //calculate ray position and direction
    a.w->cameraX = 2 * a.w->x / (double)a.w->w - 1; //x-coordinate in camera space
    a.w->rayDirX = a.w->dirX + a.w->planeX * a.w->cameraX;
    a.w->rayDirY = a.w-> dirY + a.w->planeY * a.w->cameraX;
    ft_prepdda(a);
}