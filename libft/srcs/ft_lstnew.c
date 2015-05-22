/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*cpy;

	cpy = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (list != NULL)
	{
		if (content)
		{
			cpy = (void *)malloc(content_size);
			if (!cpy)
				return (NULL);
			ft_memcpy(cpy, content, content_size);
			list->content = cpy;
		}
		else
		{
			list->content = NULL;
			content_size = 0;
		}
		list->content_size = content_size;
		list->next = NULL;
	}
	return (list);
}
