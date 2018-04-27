/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:52:28 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 23:13:53 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(size);
	if (!str)
		return (NULL);
	while (size > 1)
	{
		str[size - 1] = '\0';
		size--;
	}
	return (str);
}
