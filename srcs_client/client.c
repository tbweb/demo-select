#include "client.h"

int		main(int ac, char **av)
{
	t_env	e;

	init_client(ac, av, &e);
	main_loop(&e);
	close(e.fd.fd);
	return (0);
}