/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:22:09 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 18:29:02 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		matching;

	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		i = 0;
		matching = 0;
		if (*s1 == *s2)
		{
			matching = 1;
			while (*(s2 + i))
			{
				if (*(s2 + i) != *(s1 + i))
					matching = 0;
				i++;
			}
			if (matching)
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
