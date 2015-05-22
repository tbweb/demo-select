/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*s1c;
	char	*s2c;
	char	*cpy;

	s1c = (char *)s1;
	s2c = (char *)s2;
	if (!s1 || !s2 || !n)
	{
		return (s1);
	}
	cpy = (char *)malloc(sizeof(char *) * ft_strlen(s2) + 1);
	ft_strcpy(cpy, s2);
	while (n-- && s2c != '\0')
	{
		*s1c++ = *cpy++;
	}
	return (s1);
}
