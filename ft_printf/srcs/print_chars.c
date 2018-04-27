/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:13:19 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 20:15:44 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_char(t_format *f, va_list ap)
{
	wchar_t			w;
	unsigned char	c;

	if (f->modifier == 'l' || f->conv == 'C')
	{
		w = va_arg(ap, wchar_t);
		return (print_wide_char(f, w));
	}
	else
	{
		c = (unsigned char)va_arg(ap, int);
		return (print_ucharf(f, c));
	}
}

int		find_bin_size(int a)
{
	int		i;

	i = sizeof(int) * 8 - 1;
	while (!(a >> i) && i > 0)
		i--;
	i++;
	return (i);
}

int		print_big_wide_char(t_format *f, unsigned int w)
{
	unsigned char	octet;

	if (find_bin_size(w) <= 16)
	{
		octet = (W_MSK2 >> 16) | (((w >> 12) << 28) >> 28);
		print_ucharf(f, octet);
		octet = ((W_MSK2 << 16) >> 24) | (((w >> 6) << 26) >> 26);
		print_ucharf(f, octet);
		octet = ((W_MSK2 << 24) >> 24) | ((w << 26) >> 26);
		print_ucharf(f, octet);
		return (3);
	}
	else
	{
		octet = (W_MSK3 >> 24) | (((w >> 18) << 29) >> 29);
		print_ucharf(f, octet);
		octet = ((W_MSK3 << 8) >> 24) | (((w >> 12) << 26) >> 26);
		print_ucharf(f, octet);
		octet = ((W_MSK3 << 16) >> 24) | (((w >> 6) << 26) >> 26);
		print_ucharf(f, octet);
		octet = ((W_MSK3 << 24) >> 24) | ((w << 26) >> 26);
		print_ucharf(f, octet);
		return (4);
	}
}

int		print_wide_char(t_format *f, unsigned int w)
{
	unsigned char	octet;

	if (find_bin_size(w) <= 7)
		return (write(1, &w, 1));
	if (find_bin_size(w) <= 11)
	{
		octet = (W_MSK1 >> 8) | (((w >> 6) << 27) >> 27);
		print_ucharf(f, octet);
		octet = ((W_MSK1 << 24) >> 24) | ((w << 26) >> 26);
		print_ucharf(f, octet);
		return (2);
	}
	else
		return (print_big_wide_char(f, w));
}

int		print_ucharf(t_format *f, unsigned char c)
{
	int		l;

	l = 0;
	if (!F_ISNEG(f))
		l += ft_putnchar((F_ISZERO(f) ? '0' : ' '),
				f->min_field_w - 1);
	l += write(1, &c, 1);
	if (F_ISNEG(f))
		l += ft_putnchar(' ', f->min_field_w - 1);
	return (l);
}
