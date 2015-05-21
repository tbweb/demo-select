#include "server.h"

void	client_write(t_env *e, int cs)
{
	write(cs, e->fds[cs].buf_write, BUF_SIZE);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}