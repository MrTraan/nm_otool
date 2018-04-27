/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:54:34 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 15:12:14 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	int				lim;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	lim = (int)n;
	while (lim > 0)
	{
		if (*uc_s2 != *uc_s1)
			return ((int)*uc_s1 - (int)*uc_s2);
		lim--;
		uc_s1++;
		uc_s2++;
	}
	return (0);
}
