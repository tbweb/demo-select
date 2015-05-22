#include "client.h"

static int		create_client(t_env *e, char *host_name)
{
	struct protoent		*proto;
	struct sockaddr_in	sin;
	struct hostent		*h;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	e->fd.fd = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (!e->fd.fd)
		return (-1);
	h = gethostbyname(host_name);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(e->port);
	ft_memcpy((char *)&sin.sin_addr.s_addr, (char *)h->h_addr, h->h_length);
	if (connect(e->fd.fd, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("connection error\n");
		exit(-1);
	}
	return (e->fd.fd);
}

void			init_client(int ac, char **av, t_env *e)
{
	if (ac != 3)
		usage(av[0]);
	e->port = ft_atoi(av[2]);
	if (create_client(e, av[1]) == -1)
	{
		ft_putstr("socket or proto error\n");
		exit(-1);
	}
}
