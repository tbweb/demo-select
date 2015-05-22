/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:06 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:06 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_nm(char const *s, int k, char c)
{
	int		m;

	m = 0;
	while (s[k] != '\0')
	{
		while (s[k] != c && s[k] != '\0')
		{
			k++;
			if (s[k] == '\0' || s[k] == c)
				m++;
		}
		if (s[k] != '\0')
			k++;
	}
	return (m);
}

char		**ft_strsplitslash(char const *s, char c)
{
	char	**str;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	if ((str = ft_tabnew((ft_nm(s, i, c)))))
	{
		while (*s != '\0')
		{
			len = 0;
			while ((*s != c || (*s == c && *(s - 1) == 92)) && *s != '\0')
			{
				len++;
				if (((*++s == c) && (*(s - 1) != 92)) || *s == '\0')
					str[i++] = ft_strncpy(ft_strnew(len), (s - len), len);
			}
			if (*s != '\0')
				s = s + 1;
		}
		str[i] = NULL;
	}
	return (str);
}
