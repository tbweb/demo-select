/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:06 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:06 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*s1c == *s2c)
	{
		if (*s1c == '\0' || --n == 0)
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
	else if (*s1c > *s2c)
	{
		return (1);
	}
	return (0);
}
