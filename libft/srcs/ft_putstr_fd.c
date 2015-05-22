/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:05 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:05 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *c, int fd)
{
	int	index;

	index = 0;
	while (c[index] != '\0')
	{
		ft_putchar_fd(c[index], fd);
		index++;
	}
}
