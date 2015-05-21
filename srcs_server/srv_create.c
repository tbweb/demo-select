#include "server.h"

int					srv_create(int port)
{
	int					s;
	int					value;
	struct sockaddr_in	sin;
	struct protoent		*pe;

	value = 1;
	if ((pe = (struct protoent*)getprotobyname("tcp")) == NULL)
		return (-1);
	if ((s = socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
		return (-1);
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(int)) < 0)
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) < 0)
		return (-1);
	if (listen(s, 42) < 0)
		return (-1);
	return (s);
}
