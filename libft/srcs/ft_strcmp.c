/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:05 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:05 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1c;
	unsigned char	*s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (*s1c == *s2c)
	{
		if (*s1c == '\0')
		{
			return (0);
		}
		s1c = s1c + 1;
		s2c = s2c + 1;
	}
	if (*s1c < *s2c)
	{
		return (-1);
	}
	return (1);
}
