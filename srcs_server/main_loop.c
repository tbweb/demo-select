#include "server.h"

void	main_loop(t_env *e)
{
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	while (1)
	{
		reset_fd(e);
		e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, 0);
		check_fd(e);
	}
}