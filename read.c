#include "wolf.h"

void    ft_allocate(t_main *m)
{
    int i;
    
    i = 0;
    m->map = (int **)malloc(sizeof(int *) * m->y);
    while(i < m->y)
    {
        m->map[i] = (int *)malloc(sizeof(int) * m->x);
        i++;
    }
}

void    ft_getxy(t_main *m)
{
   int  i;
   int  c;
   char *line;
   char **str;

   m->y = 0;
   i = 0;
   while(get_next_line(m->fd, &line) > 0)
   {
       while(line[i] != '\0')
       {
           str = ft_strsplit(line, ' ');
           m->x = 0;
           c = 0;
           while(str[c++])
               m->x++;
           i++;
       }
       m->y++;
   }
   close(m->fd);
}

void    ft_readmap(t_main *m)
{
	char	*str;
	char	**st;
	int		i;
	int		x;
	int		y;

    ft_getxy(m);
    ft_allocate(m);
	y = 0;
    m->fd = open(m->file, O_RDONLY);
	while (get_next_line(m->fd, &str) > 0)
    {
		x = 0;
		i = 0;
		st = ft_strsplit(str, ' ');
		while (st[i])
		{
			m->map[y][x] = ft_atoi(st[i]);
			i++;
			x++;
		}
		y++;
	}
}