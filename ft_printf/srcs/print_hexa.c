/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:49:01 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:43:36 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	hexa_to_lower(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'F')
			s[i] -= 'A' - 'a';
		i++;
	}
}

int		print_hexa_size(t_format *f, va_list ap)
{
	size_t	c;
	char	*s;
	int		l;

	c = va_arg(ap, size_t);
	s = ft_uitoa_base((unsigned long long)c, 16);
	if (f->conv == 'x')
		hexa_to_lower(s);
	if (ft_strcmp(s, "0") == 0)
		f->flags &= ~F_ALTERNATE;
	l = print_xstringf(f, s);
	free(s);
	return (l);
}

int		print_pointer(t_format *f, va_list ap)
{
	void			*ptr;
	char			*s;
	int				l;

	ptr = va_arg(ap, void *);
	s = ft_uitoa_base((unsigned long)ptr, 16);
	hexa_to_lower(s);
	f->flags |= F_ALTERNATE;
	if (F_ISPRECIS(f) && f->precision == 0)
		l = write(1, "0x", 2);
	else
		l = print_xstringf(f, s);
	free(s);
	return (l);
}

int		print_hexa_digit(t_format *f, va_list ap)
{
	f->flags &= ~(F_SIGN | F_SPACE);
	if (f->conv == 'p')
		return (print_pointer(f, ap));
	if (f->modifier == 'H')
		return (print_hexa_signed_char(f, ap));
	else if (f->modifier == 'h')
		return (print_hexa_short(f, ap));
	else if (f->modifier == 'l' || f->conv == 'O')
		return (print_hexa_long(f, ap));
	else if (f->modifier == 'L')
		return (print_hexa_long_long(f, ap));
	else if (f->modifier == 'j')
		return (print_hexa_intmax(f, ap));
	else if (f->modifier == 'z')
		return (print_hexa_size(f, ap));
	else
		return (print_hexa_int(f, ap));
}
