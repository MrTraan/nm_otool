/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:59:07 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 14:50:27 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc_s;
	unsigned char	uc_c;
	int				lim;

	uc_s = (unsigned char *)s;
	uc_c = (unsigned char)c;
	lim = (int)n;
	while (lim > 0)
	{
		if (*uc_s == uc_c)
			return ((void *)uc_s);
		uc_s++;
		lim--;
	}
	return (NULL);
}
