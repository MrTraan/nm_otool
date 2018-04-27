/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:19:16 by ngrasset          #+#    #+#             */
/*   Updated: 2016/01/05 19:55:17 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_color(const char *str, const char *color, int light)
{
	ft_putstr("\x1B[");
	if (light)
		ft_putstr("1;");
	if (ft_strcmp(color, "red") == 0)
		ft_putstr(FT_C_RED);
	else if (ft_strcmp(color, "blue") == 0)
		ft_putstr(FT_C_BLUE);
	else if (ft_strcmp(color, "green") == 0)
		ft_putstr(FT_C_GREEN);
	else if (ft_strcmp(color, "yellow") == 0)
		ft_putstr(FT_C_YELLOW);
	else if (ft_strcmp(color, "magenta") == 0)
		ft_putstr(FT_C_MAGENTA);
	else if (ft_strcmp(color, "cyan") == 0)
		ft_putstr(FT_C_CYAN);
	else if (ft_strcmp(color, "white") == 0)
		ft_putstr(FT_C_WHITE);
	else
		ft_putstr("0m");
	ft_putstr(str);
	ft_putstr(FT_C_RESET);
}
