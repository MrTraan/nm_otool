/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:58:14 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 18:21:53 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_c;
	char	*last_occurr;

	c_c = (char)c;
	last_occurr = NULL;
	while (*s)
	{
		if (*s == c_c)
			last_occurr = (char *)s;
		s++;
	}
	if (*s == c_c)
		last_occurr = (char *)s;
	return (last_occurr);
}
