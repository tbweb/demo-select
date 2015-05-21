/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 18:07:51 by btournoi          #+#    #+#             */
/*   Updated: 2015/03/05 18:07:51 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <netdb.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/select.h>
# include <netinet/in.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

# define FD_FREE	0
# define FD_SERV	1
# define FD_CLIENT	2
# define BUF_SIZE	1000

# define MAX(a,b) ((a > b) ? a : b)

typedef struct	s_fd
{
	char		id[10];
	int			channel;
	int			type;
	void		(*fct_read)();
	void		(*fct_write)();
	char		*buf_read;
	char		buf_write[BUF_SIZE + 1];
}				t_fd;

typedef struct	s_env
{
	t_fd		*fds;
	int			port;
	int			socket;
	int			maxfd;
	int			max;
	int			r;
	fd_set		fd_read;
	fd_set		fd_write;
}				t_env;

void			check_fd(t_env *e);
void			client_read(t_env *e, int cs);
void			client_write(t_env *e, int cs);
void			close_connection(t_env *e, int cs);
void			show_new_client(int cs, struct sockaddr_in csin);
void			get_opt(t_env *e, int ac, char **av);
void 			init_env(t_env *e);
void			init_serv(t_env *e, int s);
void			main_loop(t_env *e);
void			reset_fd(t_env *e);
void			srv_accept(t_env *e, int s);
int				srv_create(int port);


#endif
