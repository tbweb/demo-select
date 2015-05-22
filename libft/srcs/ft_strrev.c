/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:06 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:06 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;
	char	t;

	i = 0;
	len = 0;
	c = 0;
	len = ft_strlen(str);
	while (i < (len / 2))
	{
		c = str[i];
		t = str[len - 1];
		str[i] = t;
		str[len - 1] = c;
		i++;
		len--;
	}
	return (str);
}
