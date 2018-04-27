/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:39:20 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 23:42:15 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*start;

	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	start = dst;
	if (!dst)
		return (NULL);
	while (*s1)
	{
		*dst = *s1;
		s1++;
		dst++;
	}
	while (*s2)
	{
		*dst = *s2;
		s2++;
		dst++;
	}
	*dst = '\0';
	return (start);
}
