/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrint(char *s)
{
	int			i;
	int			match;
	static char	cmp[11] = { '2', '1', '4', '7', '4', '8', '3', '6', '4', '7' };

	match = 0;
	i = 0;
	if (s)
	{
		if (ft_strlen(s) <= 10)
		{
			if (ft_stronlydigit(s))
				match = 1;
			if (ft_strlen(s) != 10)
				return (match);
			while (s[i])
			{
				if (s[i] <= cmp[i])
					match = 1;
				else
					return (0);
				i++;
			}
		}
	}
	return (match);
}
