/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexstrtoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:03 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:03 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hextoint(char c)
{
	if (c >= 'A' && c <= 'F')
		c = c - 7;
	else if (c >= 'a' && c <= 'f')
		c = c - 39;
	c = c - '0';
	return (c);
}

int		ft_hexstrtoi(char *str)
{
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (str[i])
	{
		if (i != 0)
			value = value * 16;
		value += ft_hextoint(str[i]);
		i++;
	}
	return (value);
}
