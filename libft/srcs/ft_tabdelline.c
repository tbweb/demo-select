/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdelline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:06 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:06 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdelline(char **tab, int line)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = ft_tabnew(ft_tablen(tab) - 1);
	while (tab[i] != '\0')
	{
		if (i != line)
		{
			new[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}
