/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:33:42 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:49:26 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_octal_short(t_format *f, va_list ap)
{
	unsigned short	c;
	char			*s;
	int				l;

	c = (unsigned short)va_arg(ap, int);
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

int		print_short(t_format *f, va_list ap)
{
	short	c;
	char	*s;
	int		l;

	c = (short)va_arg(ap, int);
	s = ft_itoa_base((long long)c, 10);
	l = print_dstringf(f, s);
	free(s);
	return (l);
}

int		print_hexa_short(t_format *f, va_list ap)
{
	unsigned short	c;
	char			*s;
	int				l;

	c = (unsigned short)va_arg(ap, int);
	s = ft_uitoa_base((unsigned long long)c, 16);
	if (f->conv == 'x')
		hexa_to_lower(s);
	if (ft_strcmp(s, "0") == 0)
		f->flags &= ~F_ALTERNATE;
	l = print_xstringf(f, s);
	free(s);
	return (l);
}

int		print_ushort(t_format *f, va_list ap)
{
	unsigned short	c;
	char			*s;
	int				l;

	c = (unsigned short)va_arg(ap, int);
	s = ft_uitoa_base((unsigned long long)c, 10);
	l = print_dstringf(f, s);
	free(s);
	return (l);
}
