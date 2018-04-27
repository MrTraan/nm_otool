/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:28:06 by ngrasset          #+#    #+#             */
/*   Updated: 2016/01/05 19:23:04 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*start;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	start = res;
	while (*s1)
	{
		*res = *s1;
		res++;
		s1++;
	}
	*res = *s1;
	return (start);
}
