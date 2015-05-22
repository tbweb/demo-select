#include "client.h"

void		read_stdin(t_env *e)
{
	int		size;

	ft_bzero(e->fd.buf_read, BUF_SIZE + 1);
	size = read(0, e->fd.buf_read, BUF_SIZE);
	write(e->fd.fd, e->fd.buf_read, size);
}