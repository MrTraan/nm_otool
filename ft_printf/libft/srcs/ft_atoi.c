/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:35:40 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/27 18:44:03 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		is_neg;

	is_neg = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\r' || *str == '\f')
		str++;
	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (-2147483648);
	if (*str == '-' || *str == '+')
	{
		is_neg = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	return (res * is_neg);
}
