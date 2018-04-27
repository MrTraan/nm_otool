/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_args_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:28:12 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 18:09:12 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		get_flags(t_format *f, char *fmt)
{
	int		l;

	l = 0;
	while (ft_strchr(VALID_FLAGS, *fmt))
	{
		if (*fmt == '#')
			f->flags |= F_ALTERNATE;
		if (*fmt == '0')
			f->flags |= F_ZERO;
		if (*fmt == '-')
			f->flags |= F_NEG;
		if (*fmt == ' ')
			f->flags |= F_SPACE;
		if (*fmt == '+')
			f->flags |= F_SIGN;
		l++;
		fmt++;
	}
	return (l);
}

int		get_min_field_w(t_format *f, char *fmt)
{
	int		l;

	l = 0;
	if (ft_isdigit(*fmt))
	{
		f->min_field_w = ft_atoi(fmt);
		while (ft_isdigit(fmt[l]))
			l++;
	}
	return (l);
}

int		get_precision(t_format *f, char *fmt)
{
	int		l;

	l = 0;
	if (*fmt == '.')
	{
		l++;
		f->flags |= F_PRECIS;
		if (ft_isdigit(fmt[1]))
		{
			f->precision = ft_atoi(fmt + 1);
			while (ft_isdigit(fmt[l]))
				l++;
		}
	}
	return (l);
}

int		get_modifier(t_format *f, char *fmt)
{
	int		l;

	l = 0;
	if (ft_strchr(VALID_MODIFIER, *fmt))
	{
		if (*fmt == 'l' && fmt[1] == 'l')
		{
			f->modifier = 'L';
			l++;
		}
		else if (*fmt == 'h' && fmt[1] == 'h')
		{
			f->modifier = 'H';
			l++;
		}
		else
			f->modifier = *fmt;
		l++;
	}
	return (l);
}

int		get_conv(t_format *f, char *fmt)
{
	f->conv = *fmt;
	if (!*fmt)
	{
		f->conv = 0;
		return (0);
	}
	return (1);
}
