/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:03 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:03 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atoui(const char *str)
{
	int				j;
	unsigned int	i;

	j = 0;
	while (str[j] == ' ' || (str[j] >= '\t' && str[j] <= '\r'))
		j++;
	if (str[j] >= '0' && str[j] <= '9')
	{
		i = str[j++] - '0';
		while (str[j] != '\0' && str[j] >= '0' && str[j] <= '9')
			i = i * 10 + (str[j++] - '0');
	}
	else
		return (0);
	return (i);
}
