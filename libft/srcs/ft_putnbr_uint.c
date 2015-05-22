/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:05 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:05 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_uint(unsigned int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr_uint(n / 10);
		ft_putnbr_uint(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}
