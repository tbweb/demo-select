#include "client.h"

int		check_fd(t_env *e)
{
	if (FD_ISSET(e->fd.fd, &e->fd_read))
	{
		return (read_fd(e));
	}
	if (FD_ISSET(0, &e->fd_read))
	{
		read_stdin(e);
	}
	return (1);
}