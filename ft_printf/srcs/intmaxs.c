/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intmaxs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:42:29 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:43:45 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_octal_intmax(t_format *f, va_list ap)
{
	uintmax_t	c;
	char		*s;
	int			l;

	c = va_arg(ap, uintmax_t);
	s = ft_uitoa_base((unsigned long long)c, 8);
	if (f->precision < (int)ft_strlen(s) && F_ISALTER(f))
	{
		f->flags |= F_PRECIS;
		f->precision = (int)ft_strlen(s) + 1;
		if (c == 0)
			f->precision--;
	}
	l = print_dstringf(f, s);
	free(s);
	return (l);
}

int		print_intmax(t_format *f, va_list ap)
{
	intmax_t	c;
	char		*s;
	int			l;

	c = va_arg(ap, intmax_t);
	s = ft_itoa_base((long long)c, 10);
	l = print_dstringf(f, s);
	free(s);
	return (l);
}

int		print_hexa_intmax(t_format *f, va_list ap)
{
	uintmax_t	c;
	char		*s;
	int			l;

	c = va_arg(ap, uintmax_t);
	s = ft_uitoa_base((unsigned long long)c, 16);
	if (f->conv == 'x')
		hexa_to_lower(s);
	if (ft_strcmp(s, "0") == 0)
		f->flags &= ~F_ALTERNATE;
	l = print_xstringf(f, s);
	free(s);
	return (l);
}

int		print_uintmax(t_format *f, va_list ap)
{
	uintmax_t	c;
	char		*s;
	int			l;

	c = va_arg(ap, uintmax_t);
	s = ft_uitoa_base((unsigned long long)c, 10);
	l = print_dstringf(f, s);
	free(s);
	return (l);
}
