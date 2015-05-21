#include "server.h"

static void		init_fd(t_fd *fd)
{
	fd->type = FD_FREE;
	fd->channel = 0;
	ft_bzero(fd->buf_read, BUF_SIZE + 1);
	ft_bzero(fd->buf_write, BUF_SIZE + 1);
	fd->fct_read = NULL;
	fd->fct_write = NULL;
}

void 			init_env(t_env *e)
{
	int				i;
	struct rlimit	rlp;

	i = 0;
	if (getrlimit(RLIMIT_NOFILE, &rlp) < 0)
	{
		ft_putendl("getrlimit error");
		exit(-1);
	}
	e->maxfd = rlp.rlim_cur;
	e->fds = (t_fd*)malloc(sizeof(*e->fds) * e->maxfd);
	if (e->fds == NULL)
	{
		ft_putendl("malloc error");
		exit(-1);
	}
	while (i < e->maxfd)
	{
		init_fd(&e->fds[i]);
		i++;
	}
} 