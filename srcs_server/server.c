#include "server.h"

int		main(int ac, char **av)
{
	t_env	e;

	init_env(&e);
	get_opt(&e, ac, av);
	e.socket = srv_create(e.port);
	if (e.socket < 0)
	{
		ft_putendl("srv_create error");
		exit(-1);
	}
	init_serv(&e, e.socket);
	main_loop(&e);
	return (0);
}