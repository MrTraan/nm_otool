/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:01:24 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 16:11:01 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*start;

	start = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = *src;
	return (start);
}
