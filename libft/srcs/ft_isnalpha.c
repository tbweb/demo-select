/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:04 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:04 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnalpha(char c, int n)
{
	int		value;
	char	c_end;

	c_end = 'a';
	c_end = c_end + n - 1;
	value = 0;
	if (c >= 'a' && c <= c_end)
		value = 1;
	else if (c >= 'A' && c <= (c_end - 32))
		value = 1;
	return (value);
}
