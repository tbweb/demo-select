/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 18:07:50 by btournoi          #+#    #+#             */
/*   Updated: 2015/05/06 17:21:11 by taudeguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include "../libft/includes/libft.h"

# define BUF_SIZE 1000

typedef struct	s_fd
{
	int			fd;
	char		buf_read[BUF_SIZE + 1];
	char		buf_write[BUF_SIZE + 1];
}				t_fd;

typedef struct	s_env
{
	t_fd		fd;
	int			port;
	int			r;
	fd_set		fd_read;
	fd_set		fd_write;
}				t_env;

#endif
