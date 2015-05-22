/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:05 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:05 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

static void	ft_putnbr_comas(double n)
{
	char	c;
	double	tmp;

	if (n != trunc(n))
	{
		tmp = trunc(n * 10);
		ft_putnbr_comas(tmp);
		n = (n * 10) - tmp;
		if (n != 0)
			ft_putnbr_comas(n);
	}
	else
	{
		c = n + '0';
		ft_putchar(c);
	}
}

void		ft_putnbr_double(double n)
{
	double	integer;

	integer = trunc(n);
	ft_putnbr((int)integer);
	n -= integer;
	if (n != 0)
	{
		if (n < 0)
			n = -n;
		ft_putchar('.');
		ft_putnbr_comas(n);
	}
}
