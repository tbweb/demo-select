#include "server.h"

void			show_new_client(int cs, struct sockaddr_in csin)
{
	char				*addr;
	uint16_t			ins;

	addr = inet_ntoa(csin.sin_addr);
	ins = ntohs(csin.sin_port);
	ft_putstr("New client #");
	ft_putnbr(cs);
	ft_putstr(" from ");
	ft_putstr(addr);
	ft_putstr(":");
	ft_putnbr(ins);
	ft_putchar('\n');
}