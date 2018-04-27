/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:58:50 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 20:11:00 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>

# define F_ALTERNATE	0xF
# define F_ZERO			0xF0
# define F_NEG			0xF00
# define F_SPACE		0xF000
# define F_SIGN			0xF0000
# define F_PRECIS		0xF00000
# define F_ISALTER(x)	(x->flags & F_ALTERNATE)
# define F_ISZERO(x)	(x->flags & F_ZERO)
# define F_ISNEG(x)		(x->flags & F_NEG)
# define F_ISSPACE(x)	(x->flags & F_SPACE)
# define F_ISSIGN(x)	(x->flags & F_SIGN)
# define F_ISPRECIS(x)	(x->flags & F_PRECIS)
# define VALID_FLAGS	"#0-+ "
# define VALID_MODIFIER	"hljz"
# define W_MSK1			49280L
# define W_MSK2			14712960L
# define W_MSK3			4034953344L
# define S_MAX(x, y)	(x > y ? x : y)
# define M_SIGN(x, y) (ft_isdigit(*y) && (F_ISSIGN(x) || F_ISSPACE(x) ? 1 : 0))

typedef struct		s_format
{
	int				flags;
	int				min_field_w;
	int				precision;
	char			modifier;
	char			conv;
}					t_format;

typedef struct		s_match_type
{
	char			*format;
	int				(*f)(t_format *, va_list);
}					t_match_type;

t_format			*new_format(void);

char				*string_concat(char *s1, char *s2);
int					find_bin_size(int a);
int					ft_printf(char *fmt, ...);
int					get_next_format(t_format **format, char *fmt);
int					print_formated(t_format *f, va_list ap);
int					get_flags(t_format *f, char *fmt);
int					get_min_field_w(t_format *f, char *fmt);
int					get_precision(t_format *f, char *fmt);
int					get_modifier(t_format *f, char *fmt);
int					get_conv(t_format *f, char *fmt);

int					print_digit(t_format *f, va_list ap);

int					print_string(t_format *f, va_list ap);
int					print_stringf(t_format *f, char *s);
int					print_dstringf(t_format *f, char *s);
int					print_xstringf(t_format *f, char *s);
int					print_ucharf(t_format *f, unsigned char c);

int					print_char(t_format *f, va_list ap);
int					print_wide_char(t_format *f, unsigned int w);

int					print_binary(t_format *f, va_list ap);

int					print_hexa_digit(t_format *f, va_list ap);

int					print_octal_digit(t_format *f, va_list ap);

int					print_udigit(t_format *f, va_list ap);

int					print_octal_long(t_format *f, va_list ap);
int					print_long_long(t_format *f, va_list ap);
int					print_hexa_long(t_format *f, va_list ap);
int					print_ulong_long(t_format *f, va_list ap);
int					print_octal_long_long(t_format *f, va_list ap);
int					print_long(t_format *f, va_list ap);
int					print_hexa_long_long(t_format *f, va_list ap);
int					print_ulong(t_format *f, va_list ap);
int					print_hexa_signed_char(t_format *f, va_list ap);
int					print_signed_char(t_format *f, va_list ap);
int					print_octal_char(t_format *f, va_list ap);
int					print_usigned_char(t_format *f, va_list ap);
int					print_octal_intmax(t_format *f, va_list ap);
int					print_intmax(t_format *f, va_list ap);
int					print_hexa_intmax(t_format *f, va_list ap);
int					print_uintmax(t_format *f, va_list ap);
int					print_octal_int(t_format *f, va_list ap);
int					print_int(t_format *f, va_list ap);
int					print_hexa_int(t_format *f, va_list ap);
int					print_uint(t_format *f, va_list ap);
int					print_octal_short(t_format *f, va_list ap);
int					print_short(t_format *f, va_list ap);
int					print_hexa_short(t_format *f, va_list ap);
int					print_ushort(t_format *f, va_list ap);

void				hexa_to_lower(char *s);
int					print_string_wide(t_format *f, wchar_t *w);
#endif
