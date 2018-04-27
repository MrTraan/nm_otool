/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:56:18 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 18:03:26 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_c;

	c_c = (char)c;
	while (*s)
	{
		if (*s == c_c)
			return ((char *)s);
		s++;
	}
	if (*s == c_c)
		return ((char *)s);
	return (NULL);
}
