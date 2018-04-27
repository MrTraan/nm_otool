/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:17:49 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 22:06:27 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (dst > src)
	{
		while (len > 0)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
		return (dst);
	}
	while (len > 0)
	{
		*c_dst = *c_src;
		c_dst++;
		c_src++;
		len--;
	}
	return (dst);
}
