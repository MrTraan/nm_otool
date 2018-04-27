/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:24:50 by exam              #+#    #+#             */
/*   Updated: 2016/03/06 20:20:12 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define NUMS "0123456789ABCDEF"

static int	size_n(long long n, int base)
{
	long long	i;
	int			j;

	i = 1;
	j = 1;
	while (n / i > (base - 1) || n / i < -(base - 1))
	{
		i *= base;
		j++;
	}
	if (n < 0)
		j++;
	return (j);
}

static int	size_un(unsigned long long n, int base)
{
	unsigned long long	i;
	int					j;

	i = 1;
	j = 1;
	while (n / i > (unsigned long long)(base - 1))
	{
		i *= base;
		j++;
	}
	return (j);
}

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

char		*ft_itoa_base(long long nbr, int base)
{
	char			*res;
	long long		i;
	char			*start;

	if (base < 2 || base > 16)
		return (NULL);
	if ((res = malloc(sizeof(char) * size_n(nbr, base) + 1)) == NULL)
		return (NULL);
	start = res;
	if (nbr < 0)
	{
		*res = '-';
		res++;
	}
	i = 1;
	while (nbr / i > (base - 1) || nbr / i < -(base - 1))
		i *= base;
	while (i > 0)
	{
		*res = NUMS[ft_abs(((nbr / i) % base))];
		res++;
		i /= base;
	}
	*res = '\0';
	return (start);
}

char		*ft_uitoa_base(unsigned long long nbr, int base)
{
	char				*res;
	unsigned long long	i;
	char				*start;

	if (base < 2 || base > 16)
		return (NULL);
	if ((res = malloc(sizeof(char) * size_un(nbr, base) + 1)) == NULL)
		return (NULL);
	start = res;
	i = 1;
	while (nbr / i > (unsigned long long)(base - 1))
		i *= base;
	while (i > 0)
	{
		*res = NUMS[ft_abs(((nbr / i) % base))];
		res++;
		i /= base;
	}
	*res = '\0';
	return (start);
}
