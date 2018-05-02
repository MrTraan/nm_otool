/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:53:48 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 16:15:17 by ngrasset         ###   ########.fr       */
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
	return (magic == MH_CIGAM || magic == MH_CIGAM_64 ||
			magic == FAT_CIGAM || magic == FAT_CIGAM_64);
}

int			is_magic_ok(t_u32 magic)
{
	return (magic == MH_MAGIC || magic == MH_MAGIC_64 ||
			magic == MH_CIGAM || magic == MH_CIGAM_64 ||
			magic == FAT_MAGIC || magic == FAT_MAGIC_64 ||
			magic == FAT_CIGAM || magic == FAT_CIGAM_64);
}

int			is_fat_magic(t_u32 magic)
{
	return (magic == FAT_MAGIC || magic == FAT_CIGAM || is_fat_64(magic));
}
