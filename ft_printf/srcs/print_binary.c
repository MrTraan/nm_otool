/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:50:23 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/03 19:58:01 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_binary(t_format *f, va_list ap)
{
	int		a;
	int		i;
	int		sum;

	(void)f;
	sum = 0;
	a = va_arg(ap, int);
	i = 31;
	while (!(a >> i) && i > 0)
		i--;
	while (i >= 0)
	{
		if ((a >> i) & 1)
			sum += write(1, "1", 1);
		else
			sum += write(1, "0", 1);
		i--;
	}
	return (sum);
}
