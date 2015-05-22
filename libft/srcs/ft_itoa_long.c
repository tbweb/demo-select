/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_str_size(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	len++;
	while (n / 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void		ft_convert(char *str, long n, int size)
{
	int		minus;

	minus = 0;
	if (n < 0)
		minus = 1;
	str[size] = '\0';
	size--;
	while (size)
	{
		if (n > 0)
			str[size] = (n % 10) + '0';
		else if (n < 0)
			str[size] = (-(n % 10)) + '0';
		else
			str[size] = '0';
		n /= 10;
		size--;
	}
	if (minus)
		str[size] = '-';
	else
		str[size] = n + '0';
}

char			*ft_itoa_long(long n)
{
	char	*str;

	str = NULL;
	str = (char*)malloc(sizeof(char) * (ft_str_size(n) + 1));
	if (str)
		ft_convert(str, n, ft_str_size(n));
	return (str);
}
