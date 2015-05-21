#include "server.h"

void	init_serv(t_env *e, int s)
{
	e->fds[s].id[0] = 0;
	e->fds[s].channel = 0;
	e->fds[s].type = FD_SERV;
	e->fds[s].fct_read = srv_accept;
}