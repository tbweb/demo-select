/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:03 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:03 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_btoi(long n)
{
	long	decimal;
	long	i;
	long	rem;

	decimal = 0;
	i = 0;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		decimal += rem * ft_pow(2, i);
		i++;
	}
	return (decimal);
}
