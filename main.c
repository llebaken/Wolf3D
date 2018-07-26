#include "wolf.h"

void    ft_sdl(t_main *a)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        ft_putstr("Error initialising SDL");
        exit(0);
    }
    a->s.win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 512, 384, 0);
    a->s.ren = SDL_CreateRenderer(a->s.win, -1, 0);
    if (!a->s.win || !a->s.ren)
    {
        ft_putstr("Error initialising SDL");
        exit(0);
    }
}

void    ft_initialise(t_main *m)
{   
    m->w.posX = 22;
    m->w.posY = 12;
    m->w.dirX = -1;
    m->w.dirY = 0;
    m->w.planeX = 0;
    m->w.planeY = 0.66;
    m->w.time = 0;
    m->w.oldtime = 0;
    m->w.x = 0;
    m->w.y = 0;
    m->w.w = 512;
    m->w.h = 384;
}

int     main(int ac, char **av)
{
    t_main m;

    if ((ac != 2) || (!ft_strstr(av[1], ".w3d")))
	{
		ft_putstr("Please add .w3d file\n");
	}
    else if ((m.fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("File cannot be read\n.");
	}
    else
    {
        m.file = av[1];
        ft_readmap(&m);
        ft_sdl(&m);
        ft_initialise(&m);
        /*while (m.w.quit != -1)
        {
            while (a.w.x++ < a.w.w)
                ft_wolf(&a);
            //ft_keypress(&a);
        }*/
        SDL_DestroyWindow(m.s.win);
        SDL_Quit();
    }
    return(0);
}