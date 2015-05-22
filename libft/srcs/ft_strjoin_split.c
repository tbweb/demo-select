/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:05 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:05 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strjoin_split(char **tab, char *str)
{
	int		size;
	int		i;
	char	*tmp;

	if (tab[0])
	{
		size = ft_tablen(tab);
		i = 0;
		tmp = tab[i];
		while (i < (size - 1))
		{
			tmp = ft_strjoin(tmp, str);
			tmp = ft_strjoin(tmp, tab[i + 1]);
			i++;
		}
		if (size == 1)
			tmp = ft_strdup(tmp);
	}
	else
		tmp = ft_strdup("");
	return (tmp);
}
