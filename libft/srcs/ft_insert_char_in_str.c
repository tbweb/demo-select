/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char_in_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:03 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:03 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_insert_char_in_str(char *s, char c, int pos)
{
	int		len;
	char	*new;

	len = 0;
	if (s)
		len = ft_strlen(s);
	if (pos > len || pos < 0)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	if (s)
		ft_strncpy(new, s, pos);
	new[pos] = c;
	if (pos + 1 < len && s)
		ft_strcpy(new + pos + 1, s + pos);
	new[len + 1] = '\0';
	return (new);
}
