/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:53:09 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/25 16:38:00 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_words(char const *s, char c)
{
	int		in;
	int		count;

	in = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
			in = 1;
		else
		{
			if (in)
				count++;
			in = 0;
		}
		s++;
	}
	if (in)
		count++;
	return (count);
}
