/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:29:30 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 22:43:03 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		matching;

	if (!*s2)
		return ((char *)s1);
	while (*s1 && n > 0)
	{
		i = 0;
		matching = 0;
		if (*s1 == *s2)
		{
			matching = 1;
			while (*(s2 + i) && i <= (int)n)
			{
				if (*(s2 + i) != *(s1 + i))
					matching = 0;
				i++;
			}
			if (matching && i <= (int)n)
				return ((char *)s1);
		}
		s1++;
		n--;
	}
	return (NULL);
}
