#include "wolf.h"

void	ft_color(t_main *a)
{
	if (a->map[a->w.mapX][a->w.mapY] == 1)
		SDL_SetRenderDrawColor((a->s.ren, 255, 0, 0, 255);
	else if (a->map[a->w.mapX][a->w.mapY] == 2)
		SDL_SetRenderDrawColor((a->s.ren, 255, 0, 0, 255);
	else if (a->map[a->w.mapX][a->w.mapY] == 3)
		SDL_SetRenderDrawColor((a->s.ren, 255, 0, 0, 255);
	else if (a->map[a->w.mapX][a->w.mapY] == 4)
		SDL_SetRenderDrawColor((a->s.ren, 255, 0, 0, 255);
	else
		SDL_SetRenderDrawColor((a->s.ren, 255, 0, 0, 255);
	if (a->w.side)
	{
		if (a->map[a->w.mapX][a->w.mapY] == 1)
			SDL_SetRenderDrawColor(a->s.ren, 128, 0, 0, 128);
		else if (a->map[a->w.mapX][a->w.mapY] == 2)
			SDL_SetRenderDrawColor(a->s.ren, 0, 128, 0, 128);
		else if (a->map[a->w.mapX][a->w.mapY] == 3)
			SDL_SetRenderDrawColor(a->s.ren, 0, 0, 128, 128);
		else if (a->map[a->w.mapX][a->w.mapY] == 4)
			SDL_SetRenderDrawColor(a->s.ren, 128, 128, 128, 128);
		else
			SDL_SetRenderDrawColor(a->s.ren, 128, 128, 0, 128);
	}
}

void    ft_draw(t_main *a)
{
    int temp;

    ft_color(a);
    temp = a->w.drawStart;
    while(temp < a->w.drawEnd)
        SDL_RenderDrawPoint(a->s.ren, a->w.x, i++);
}