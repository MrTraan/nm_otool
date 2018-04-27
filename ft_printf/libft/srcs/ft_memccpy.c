/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:05:14 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/23 16:34:09 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	unsigned char	uc_to_find;
	int				lim;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	uc_to_find = (unsigned char)c;
	lim = (int)n;
	while (lim > 0)
	{
		*uc_dst = *uc_src;
		if (*uc_src == uc_to_find)
			return ((void *)uc_dst + 1);
		uc_dst++;
		uc_src++;
		lim--;
	}
	return (NULL);
}
