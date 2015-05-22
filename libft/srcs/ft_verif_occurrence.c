/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_occurrence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:07 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:07 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_verif_occurence(const char *s, int c, int occur)
{
	int		i;
	int		match;

	i = 0;
	match = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			match++;
		i++;
	}
	if (s[i] == (char)c)
		match++;
	if (match == occur)
		return (1);
	else
		return (0);
}
