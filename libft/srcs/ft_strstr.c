/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:06 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:06 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	i_cpy;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		i_cpy = i;
		while (s1[i_cpy] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
			{
				return ((char *)(s1 + (i_cpy - (ft_strlen(s2) - 1))));
			}
			i_cpy++;
		}
		i++;
	}
	return (NULL);
}
