#include "client.h"

void	main_loop(t_env *e)
{
	while (1)
	{
		init_fd(e);
		e->r = select(e->fd.fd + 1, &e->fd_read, NULL, NULL, NULL);
		if (!check_fd(e))
			return ;
	}
}