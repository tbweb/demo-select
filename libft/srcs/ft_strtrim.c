/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:06 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:06 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	if (s[0] == '\0')
		return (ft_strdup(""));
	if (s)
	{
		while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != '\0')
		{
			if (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
				j++;
			else
				j = 0;
			i++;
		}
		if (i > 0)
			return (ft_strsub(s, start, i - j - start));
	}
	return (NULL);
}
