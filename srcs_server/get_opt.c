#include "server.h"

void	get_opt(t_env *e, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putstr(" port\n");
		exit(1);
	}
	e->port = ft_atoi(av[1]);
}