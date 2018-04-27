/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings_wide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:53:49 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 20:16:29 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		str_widelen(wchar_t *w)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (w[j])
	{
		if (find_bin_size(w[j]) <= 7)
			i++;
		else if (find_bin_size(w[j]) <= 11)
			i += 2;
		else if (find_bin_size(w[j]) <= 16)
			i += 3;
		else
			i += 4;
		j++;
	}
	return (i);
}

static int		print_wide_big_one(unsigned int w)
{
	unsigned char	octet;

	if (find_bin_size(w) <= 16)
	{
		octet = (W_MSK2 >> 16) | (((w >> 12) << 28) >> 28);
		write(1, &octet, 1);
		octet = ((W_MSK2 << 16) >> 24) | (((w >> 6) << 26) >> 26);
		write(1, &octet, 1);
		octet = ((W_MSK2 << 24) >> 24) | ((w << 26) >> 26);
		write(1, &octet, 1);
		return (3);
	}
	else
	{
		octet = (W_MSK3 >> 24) | (((w >> 18) << 29) >> 29);
		write(1, &octet, 1);
		octet = ((W_MSK3 << 8) >> 24) | (((w >> 12) << 26) >> 26);
		write(1, &octet, 1);
		octet = ((W_MSK3 << 16) >> 24) | (((w >> 6) << 26) >> 26);
		write(1, &octet, 1);
		octet = ((W_MSK3 << 24) >> 24) | ((w << 26) >> 26);
		write(1, &octet, 1);
		return (4);
	}
}

static int		print_wide_one(unsigned int w)
{
	unsigned char	octet;

	if (find_bin_size(w) <= 7)
		return (write(1, &w, 1));
	if (find_bin_size(w) <= 11)
	{
		octet = (W_MSK1 >> 8) | (((w >> 6) << 27) >> 27);
		write(1, &octet, 1);
		octet = ((W_MSK1 << 24) >> 24) | ((w << 26) >> 26);
		write(1, &octet, 1);
		return (2);
	}
	else
		return (print_wide_big_one(w));
}

int				print_string_wide(t_format *f, wchar_t *w)
{
	int		l;
	int		i;
	int		size;

	l = 0;
	i = 0;
	size = (F_ISPRECIS(f) && f->precision < str_widelen(w) ?
		f->precision : str_widelen(w));
	if (!F_ISNEG(f))
		l += ft_putnchar((f->flags & F_ZERO ? '0' : ' '),
				f->min_field_w - size);
	while (w[i] && (!F_ISPRECIS(f) || l < f->precision))
	{
		l += print_wide_one(w[i]);
		i++;
	}
	if (F_ISNEG(f))
		l += ft_putnchar((f->flags & F_ZERO ? '0' : ' '),
				f->min_field_w - size);
	return (l);
}
