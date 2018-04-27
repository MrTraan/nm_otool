/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:51:19 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 14:43:49 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;

	copy = (unsigned char *)b;
	while (len > 0)
	{
		*copy = (unsigned char)c;
		len--;
		copy++;
	}
	return (b);
}
