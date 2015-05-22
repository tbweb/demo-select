/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnodecontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:03 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:03 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_delnodecontent(void *content, size_t content_size)
{
	content_size = 0;
	if (content)
		free(content);
	content_size += 0;
}
