/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:53:48 by ngrasset          #+#    #+#             */
/*   Updated: 2018/04/26 15:07:44 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

t_u32		read_magic(void *file, int offset)
{
	return (*((t_u32*)(file + offset)));
}

int			is_magic_64(t_u32 magic)
{
	return (magic == MH_MAGIC_64 || magic == MH_CIGAM_64);
}

int			should_swap_bytes(t_u32 magic)
{
	return (magic == MH_CIGAM || magic == MH_CIGAM_64);
}
