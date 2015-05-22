/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:05 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:05 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlstsize(t_list *lst)
{
	while (lst)
	{
		ft_putnbr(lst->content_size);
		ft_putstr(" : ");
		ft_putendl(lst->content);
		lst = lst->next;
	}
}
