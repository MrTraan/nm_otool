/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:07:05 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/25 17:21:08 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_fill_res(char *res, int n, int pow)
{
	if (n < 0)
	{
		*res = '-';
		res++;
		if (n == -2147483648)
		{
			pow /= 10;
			*res = '2';
			res++;
			n += 2000000000;
		}
		n = -n;
	}
	while (pow > 0)
	{
		*res = '0' + ((n / pow) % 10);
		pow /= 10;
		res++;
	}
}

char		*ft_itoa(int n)
{
	int		pow;
	size_t	size;
	char	*res;

	size = 1;
	pow = 1;
	while (n / pow >= 10 || n / pow <= -10)
	{
		pow *= 10;
		size++;
	}
	res = ft_strnew(size + 1 + (n < 0 ? 1 : 0));
	if (!res)
		return (NULL);
	ft_itoa_fill_res(res, n, pow);
	return (res);
}
