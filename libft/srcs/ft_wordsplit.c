/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:07 by btournoi          #+#    #+#             */
/*   Updated: 2015/02/16 14:29:07 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static void		ft_flag_quote(char const *s, int i, int flags[2])
{
	if (flags[0])
	{
		if (s[i] == '\'')
			--flags[0];
	}
	else if (flags[1])
	{
		if (s[i] == '\"')
			--flags[1];
	}
	else
	{
		if (s[i] == '\'')
			++flags[0];
		else if (s[i] == '\"')
			++flags[1];
	}
}

static int		ft_strsplit_len(char const *s, char *split, size_t split_len)
{
	int		i;
	int		len;
	int		flags[2];

	i = 0;
	len = 0;
	flags[0] = 0;
	flags[1] = 0;
	while (s[i] != '\0')
	{
		ft_flag_quote(s, i, flags);
		if (!ft_strnstr(s + i, split, split_len)
			&& !flags[0] && !flags[1]
			&& (ft_strnstr(s + i + 1, split, split_len)
				|| s[i + 1] == '\0'))
		{
			i += split_len;
			++len;
		}
		++i;
	}
	return (len);
}

static size_t	ft_split_not_quote(char const *s, char *split, size_t split_len,
									int *i)
{
	int		flags[2];
	size_t	len;

	flags[0] = 0;
	flags[1] = 0;
	len = 0;
	while ((!ft_strnstr(s + *i, split, split_len)
			|| flags[0] || flags[1]) && s[*i] != '\0')
	{
		ft_flag_quote(s, *i, flags);
		if (s[*i] == '\\')
		{
			++len;
			++(*i);
		}
		++len;
		++(*i);
	}
	return (len);
}

static char		**ft_for_strsub(char const *s, char *split, char **str,
								int nb_str)
{
	int		i;
	int		j;
	size_t	start_string;
	size_t	len;
	size_t	split_len;

	i = 0;
	j = -1;
	split_len = ft_strlen(split);
	while (s[i] != '\0')
	{
		if (!ft_strnstr(s + i, split, split_len) && nb_str > 0)
		{
			--nb_str;
			start_string = i;
			len = ft_split_not_quote(s, split, split_len, &i);
			str[++j] = ft_strsub(s, start_string, len);
		}
		else
			i += split_len;
	}
	str[++j] = NULL;
	return (str);
}

char			**ft_wordsplit(char const *s, char *split)
{
	int		nb_str;
	char	**str;

	nb_str = 0;
	if (!s)
		return (NULL);
	if (!split)
	{
		if (!(str = (char**)malloc(sizeof(char*) * 1)))
			return (NULL);
		str[0] = ft_strdup(s);
		str[1] = NULL;
		return (str);
	}
	nb_str = ft_strsplit_len(s, split, ft_strlen(split));
	if (!(str = (char**)malloc(sizeof(char*) * (nb_str + 1))))
		return (NULL);
	str = ft_for_strsub(s, split, str, nb_str);
	return (str);
}
