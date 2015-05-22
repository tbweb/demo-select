/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:03 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:03 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int	ft_free_t_line(int fd, t_line *suppr, t_line **begin_line)
{
	t_line	*tmp;

	tmp = *begin_line;
	ft_strdel(&suppr->stor);
	if (tmp->fd == fd)
		tmp = tmp->next;
	else
	{
		while (tmp->next->fd != fd)
			tmp = tmp->next;
		tmp->next = suppr->next;
	}
	free(suppr);
	return (0);
}
