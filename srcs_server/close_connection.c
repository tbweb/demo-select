#include "server.h"

static void	clean_fd(t_fd *fd)
{
	fd->type = FD_FREE;
	fd->channel = 0;
	ft_bzero(fd->buf_read, BUF_SIZE);
	ft_bzero(fd->buf_write, BUF_SIZE);
	fd->fct_read = NULL;
	fd->fct_write = NULL;
}

void		close_connection(t_env *e, int cs)
{
	if (close(cs) < 0)
	{
		ft_putstr("close socket ");
		ft_putnbr(cs);
		ft_putendl(" not good");
	}
	else
	{
		clean_fd(&e->fds[cs]);
		ft_putstr("client #");
		ft_putnbr(cs);
		ft_putendl("gone away");
	}
}