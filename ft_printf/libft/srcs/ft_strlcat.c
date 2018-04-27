/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:14:46 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 17:47:48 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	origin_size;
	size_t	len;

	origin_size = size;
	len = ft_strlen(dst) + ft_strlen(src);
	while (*dst && size > 0)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (ft_strlen(src) + origin_size);
	while (size > 1 && *src)
	{
		*dst = *src;
		size--;
		dst++;
		src++;
	}
	*dst = '\0';
	return (len);
}
