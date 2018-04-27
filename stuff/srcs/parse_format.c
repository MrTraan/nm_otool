/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:59:03 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:52:07 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			ft_printf(char *fmt, ...)
{
	t_format	*f;
	va_list		ap;
	int			total;

	total = 0;
	va_start(ap, fmt);
	f = NULL;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt += get_next_format(&f, fmt + 1);
			total += print_formated(f, ap);
			if (f)
			{
				free(f);
				f = NULL;
			}
		}
		else
			total += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (total);
}

int			get_next_format(t_format **format, char *fmt)
{
	t_format	*f;
	int			l;

	*format = NULL;
	if (!(f = new_format()))
		return (2);
	l = 0;
	l += get_flags(f, fmt);
	l += get_min_field_w(f, fmt + l);
	l += get_precision(f, fmt + l);
	l += get_modifier(f, fmt + l);
	l += get_conv(f, fmt + l);
	*format = f;
	return (l);
}
