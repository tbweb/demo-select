/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:07 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:07 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabncpy(char **tab1, char **tab2, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tab1[i] = tab2[i];
		i++;
	}
	tab1[i] = NULL;
	return (tab1);
}
