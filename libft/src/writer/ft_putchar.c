/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:04:33 by ngrasset          #+#    #+#             */
/*   Updated: 2018/04/27 13:47:01 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

int		ft_putnchar(char c, int i)
{
	int		ret;

	ret = 0;
	while (i > 0)
	{
		ft_putchar(c);
		i--;
		ret++;
	}
	return (ret);
}
