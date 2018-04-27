/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:14:32 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/03 16:15:20 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_format	*new_format(void)
{
	t_format	*f;

	if (!(f = malloc(sizeof(t_format))))
		return (NULL);
	f->flags = 0;
	f->min_field_w = 0;
	f->precision = 0;
	f->modifier = 0;
	f->conv = 0;
	return (f);
}
