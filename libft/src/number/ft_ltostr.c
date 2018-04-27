/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 16:15:22 by ngrasset          #+#    #+#             */
/*   Updated: 2017/02/05 16:25:10 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_ltostr_fill_res(char *res, long long n, int pow)
{
	while (pow > 0)
	{
		*res = '0' + ((n / pow) % 10);
		pow /= 10;
		res++;
	}
}

char		*ft_ltostr(long long n)
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
	if (n < 0)
	{
		*res = '-';
		ft_ltostr_fill_res(res + 1, n, pow);
	}
	else
		ft_ltostr_fill_res(res, n, pow);
	return (res);
}
