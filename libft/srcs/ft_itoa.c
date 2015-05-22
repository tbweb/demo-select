/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_add_all_digit(char *str, int i, int divisor, int n)
{
	while (n % divisor > 0)
	{
		str[++i] = (n / divisor) + '0';
		n = n % divisor;
		divisor = divisor / 10;
	}
	if (divisor != 1)
		n = n / divisor;
	str[++i] = n + '0';
	while (divisor != 1)
	{
		divisor = divisor / 10;
		str[++i] = '0';
	}
	str[++i] = '\0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		divisor;

	i = -1;
	divisor = 1;
	str = ft_strnew(12);
	if (!str)
		return (NULL);
	while (n / divisor > 9 || n / divisor < (-9))
		divisor = divisor * 10;
	if (n < -9)
	{
		str[++i] = '-';
		str[++i] = -(n / divisor) + '0';
		n = -(n % divisor);
		divisor = divisor / 10;
	}
	else if (n < 0)
	{
		str[++i] = '-';
		n = -n;
	}
	ft_add_all_digit(str, i, divisor, n);
	return (str);
}
