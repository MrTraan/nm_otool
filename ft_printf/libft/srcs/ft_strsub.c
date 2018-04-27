/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:21:46 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 23:36:36 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < start)
	{
		s++;
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst[i] = *s;
		s++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
