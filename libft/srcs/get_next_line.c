/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-mint <fle-mint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:45:54 by fle-mint          #+#    #+#             */
/*   Updated: 2015/02/03 15:29:57 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static t_line	*ft_newnode(char *data, int const fd, ssize_t ret)
{
	t_line			*new;

	new = (t_line*)malloc(sizeof(t_line));
	if (new)
	{
		new->fd = fd;
		new->ret = ret;
		new->len = ret;
		new->len_stor = ret;
		new->next = NULL;
		if (!data)
			new->stor = NULL;
		else
			new->stor = data;
	}
	return (new);
}

static t_line	*ft_if_no_line(int const fd, t_line *tmp)
{
	char			*read_line;
	char			*tmp_chr;

	while (!(ft_ismemchr(tmp->stor, '\n', tmp->len)) && tmp->ret != 0)
	{
		if ((read_line = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
			tmp->ret = -1;
		if (tmp->ret == -1)
			return (tmp);
		if ((tmp->ret = read(fd, read_line, BUFF_SIZE)) != -1)
		{
			tmp_chr = tmp->stor;
			tmp->stor = ft_memjoin(tmp_chr, read_line, tmp->len, tmp->ret);
			free(tmp_chr);
			tmp->len += tmp->ret;
		}
		free(read_line);
		if (tmp->ret == -1)
			return (tmp);
	}
	if (ft_ismemchr(tmp->stor, '\n', tmp->len))
		tmp->len_stor = ft_memchrlen(tmp->stor, '\n', tmp->len);
	else
		tmp->len_stor = tmp->len;
	return (tmp);
}

static t_line	*ft_find_fd(int const fd, t_line *tmp, ssize_t *ret)
{
	char			*read_line;
	t_line			*tmp_last;

	if (tmp)
	{
		while (fd != tmp->fd && tmp->next != NULL)
			tmp = tmp->next;
	}
	if (tmp->next == NULL && fd != tmp->fd)
	{
		if ((read_line = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		{
			*ret = -1;
			return (tmp);
		}
		*ret = read(fd, read_line, BUFF_SIZE);
		if (*ret == -1)
			return (tmp);
		tmp_last = ft_newnode(read_line, fd, *ret);
		tmp->next = tmp_last;
		tmp = tmp->next;
	}
	tmp = ft_if_no_line(fd, tmp);
	return (tmp);
}

static t_line	*ft_check_line(int const fd, t_line **begin_line, ssize_t *ret)
{
	char			*read_line;

	if (!(*begin_line))
	{
		if ((read_line = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		{
			*ret = -1;
			return ((*begin_line));
		}
		*ret = read(fd, read_line, BUFF_SIZE);
		if (*ret != -1)
		{
			(*begin_line) = ft_newnode(read_line, fd, *ret);
			(*begin_line) = ft_if_no_line(fd, (*begin_line));
		}
	}
	else if (fd == (*begin_line)->fd)
		return (ft_if_no_line(fd, (*begin_line)));
	else if (fd != (*begin_line)->fd)
		return (ft_find_fd(fd, (*begin_line), ret));
	return ((*begin_line));
}

int				get_next_line(int const fd, char **line)
{
	static t_line	*begin_line;
	t_line			*tmp;
	ssize_t			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	tmp = ft_check_line(fd, &begin_line, &ret);
	if (ret == -1)
		return (ret);
	if (tmp->ret == 0 && tmp->len == 0)
		return (ft_free_t_line(fd, tmp, &begin_line));
	else
		tmp->ret = 1;
	if (tmp->len_stor == 0 && tmp->ret == 0)
		tmp->len_stor = tmp->len;
	if ((*line = (char*)malloc(sizeof(char) * (tmp->len_stor + 1))) == NULL)
		return (-1);
	*line = ft_memset(*line, '\0', tmp->len_stor + 1);
	*line = ft_memcpy(*line, tmp->stor, tmp->len_stor);
	tmp->len -= tmp->len_stor;
	if (tmp->len > 0)
		tmp->len -= 1;
	tmp->stor = ft_memcpy(tmp->stor, (tmp->stor) + tmp->len_stor + 1, tmp->len);
	return (tmp->ret);
}
