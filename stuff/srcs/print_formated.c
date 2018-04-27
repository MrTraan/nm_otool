/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:03:51 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:50:10 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	print_no_conv(t_format *f, va_list ap)
{
	(void)ap;
	return (print_ucharf(f, f->conv));
}

t_match_type	g_match_tab[] = {
	{"dDi", print_digit},
	{"sS", print_string},
	{"Cc", print_char},
	{"b", print_binary},
	{"pxX", print_hexa_digit},
	{"oO", print_octal_digit},
	{"uU", print_udigit},
	{"%", print_no_conv},
	{NULL, NULL}
};

int			print_formated(t_format *f, va_list ap)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (g_match_tab[i].format)
	{
		if (ft_strchr(g_match_tab[i].format, f->conv))
			return (g_match_tab[i].f(f, ap));
		i++;
	}
	return (print_no_conv(f, ap));
}
