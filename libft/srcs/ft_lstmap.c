/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstc;
	t_list	*tmp;

	lstc = NULL;
	if (lst && f)
	{
		lstc = ft_lstnew(lst->content, lst->content_size);
		if (!lstc)
			return (NULL);
		tmp = f(lstc);
		lstc = tmp;
		while (lst->next != NULL)
		{
			lst = lst->next;
			tmp->next = ft_lstnew(lst->content, lst->content_size);
			if (!tmp->next)
			{
				free(lstc);
				return (NULL);
			}
			tmp->next = f(tmp->next);
			tmp = tmp->next;
		}
	}
	return (lstc);
}
