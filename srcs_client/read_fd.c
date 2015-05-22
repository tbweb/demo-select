#include "client.h"

int			read_fd(t_env *e)
{
	int		size;
	char	cmd_prompt[7];

	ft_strcpy(cmd_prompt, "prompt");
	ft_bzero(e->fd.buf_read, BUF_SIZE + 1);
	size = recv(e->fd.fd, e->fd.buf_read, BUF_SIZE, 0);
	if (size > 0)
		return (1);
	return (0);
}