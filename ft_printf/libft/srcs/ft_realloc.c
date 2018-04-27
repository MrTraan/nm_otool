/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:25:17 by ngrasset          #+#    #+#             */
/*   Updated: 2016/01/17 19:30:07 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t o_size, size_t n_size)
{
	char	*dst;

	if (!ptr)
		return (NULL);
	if (n_size < o_size)
		return (ptr);
	dst = malloc(n_size);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, n_size);
	ft_memcpy(dst, ptr, o_size);
	free(ptr);
	return (dst);
}
