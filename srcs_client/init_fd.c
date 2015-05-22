#include "client.h"

void	init_fd(t_env *e)
{
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	FD_SET(e->fd.fd, &e->fd_read);
	FD_SET(0, &e->fd_read);
}
