/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabaddstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:06 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:06 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabaddstr(char **tab, char *str)
{
	int		i;
	int		len;
	char	**new;

	i = 0;
	len = ft_tablen(tab);
	new = ft_tabnew(len + 1);
	while (i < len)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	return (new);
}
