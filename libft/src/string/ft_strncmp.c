/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:22:15 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 22:35:25 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*uc_s1 && n > 1)
	{
		if (*uc_s1 != *uc_s2)
			return ((int)(*uc_s1 - *uc_s2));
		uc_s1++;
		uc_s2++;
		n--;
	}
	return ((int)(*uc_s1 - *uc_s2));
}
