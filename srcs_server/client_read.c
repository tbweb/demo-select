#include "server.h"

void		client_read(t_env *e, int cs)
{
	int		r;

//	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0); //get_next_line
	r = get_next_line(cs, &e->fds[cs].buf_read);
	if (r <= 0)
		close_connection(e, cs);
	else if (e->fds[cs].buf_read)
	{
		ft_putendl(e->fds[cs].buf_read);
		ft_strdel(&e->fds[cs].buf_read);
	}
}