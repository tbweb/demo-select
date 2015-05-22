/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:07 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:07 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabnew(size_t size)
{
	char	**tab;
	size_t	i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (i < size + 1)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}
