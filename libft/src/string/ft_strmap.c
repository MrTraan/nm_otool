/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:04:21 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 23:13:13 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	char	*start;

	dst = (char *)malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	start = dst;
	while (*s)
	{
		*dst = (*f)(*s);
		s++;
		dst++;
	}
	*dst = '\0';
	return (start);
}
