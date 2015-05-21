#include "server.h"

static void			init_name_client(t_env *e, int cs)
{
	char		*fd;
	char		*tmp;

	fd = ft_itoa(cs);
	tmp = ft_strjoin("client#", fd);
	ft_strncpy(e->fds[cs].id, tmp, 9);
	e->fds[cs].id[9] = 0;
	ft_strdel(&tmp);
	ft_strdel(&fd);
}

static void			init_client(t_env *e, int cs)
{
	e->fds[cs].type = FD_CLIENT;
	e->fds[cs].channel = 0;
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
	init_name_client(e, cs);
}

void				srv_accept(t_env *e, int s)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;

	csin_len = sizeof(csin);
	if ((cs = accept(s, (struct sockaddr*)&csin, &csin_len)) < 0)
		return ;
	show_new_client(cs, csin);
	init_client(e, cs);
	write(cs, "OK\n", 3);
}