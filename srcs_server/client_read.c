#include "server.h"

void		client_read(t_env *e, int cs)
{
	int		r;

	ft_bzero(e->fds[cs].buf_read, BUF_SIZE);
	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0); //get_next_line
	if (r <= 0)
		close_connection(e, cs);
}