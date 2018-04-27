/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:53:36 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/25 14:40:34 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		start;
	int		lim;
	int		i;

	i = 0;
	start = 0;
	lim = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[lim] != '\0')
		lim++;
	lim = lim == 0 ? 0 : lim - 1;
	while ((s[lim] == ' ' || s[lim] == '\n' || s[lim] == '\t') &&
			lim >= start)
		lim--;
	dst = ft_strnew(lim - start + 1);
	while (dst && start <= lim)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	return (dst);
}
