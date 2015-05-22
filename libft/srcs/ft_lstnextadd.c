/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnextadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstnextadd(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else
	{
		(*alst)->next = new;
		*alst = (*alst)->next;
	}
}
