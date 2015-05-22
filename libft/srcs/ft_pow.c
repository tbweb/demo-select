/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	ft_pow(double x, double y)
{
	double	i;
	double	res;

	i = 1;
	res = x;
	if (!y)
		return (1);
	if (y == 1)
		return (x);
	while (i < y)
	{
		res *= x;
		i++;
	}
	return (res);
}
