/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:18:35 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/30 16:26:50 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_search_and_replace(char *s, char a, char b)
{
	char	*start;

	if (!s)
		return (NULL);
	start = s;
	while (*s)
	{
		if (*s == a)
			*s = b;
		s++;
	}
	return (start);
}
