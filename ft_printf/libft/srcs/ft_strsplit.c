/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:44:11 by ngrasset          #+#    #+#             */
/*   Updated: 2016/01/06 14:22:40 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**start;
	char		**tab;
	int			count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (count_words + 1))))
		return (NULL);
	start = tab;
	while (count_words-- > 0)
	{
		while (*s == c)
			s++;
		*tab = ft_strsub(s, 0, ft_strnlen(s, c));
		s += ft_strnlen(s, c);
		tab++;
	}
	*tab = NULL;
	return (start);
}
