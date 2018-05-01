/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:03:10 by ngrasset          #+#    #+#             */
/*   Updated: 2018/04/28 16:47:31 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		is_fat_64(t_u32 magic)
{
	return (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64);
}

int		is_fat_magic(t_u32 magic)
{
	return (magic == FAT_MAGIC || magic == FAT_CIGAM || is_fat_64(magic));
}

void	handle_fat_64(t_file *file, t_u32 magic, int should_swap)
{
	(void)file;
	(void)magic;
	(void)should_swap;
}

void	handle_fat(t_file *file, t_u32 magic, int should_swap)
{
	struct fat_header	*fh;
	struct fat_arch		*fa;
	t_file				sub_file;
	t_u32				i;
	const char			*arch_name;	

	if (is_fat_64(magic))
		return (handle_fat_64(file, magic, should_swap));
	fh = (struct fat_header *)(file->data);
	if (should_swap)
		swap_fat_header(fh, 0);
	i = 0;
	while (i < fh->nfat_arch)
	{
		fa = (struct fat_arch *)((void *)file->data + sizeof(struct fat_header) + i * sizeof(struct fat_arch));
		if (should_swap)
			swap_fat_arch(fa, 1, 0);
		if (fa->cputype == CPU_TYPE_X86_64 || fh->nfat_arch == 1)
		{
			sub_file.path = file->path;
			sub_file.data = file->data + fa->offset;
			sub_file.size = fa->size;
			dump_segments(&sub_file);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < fh->nfat_arch)
	{
		fa = (struct fat_arch *)((void *)file->data + sizeof(struct fat_header) + i * sizeof(struct fat_arch));
		arch_name = get_cpu_name(fa->cputype);
		sub_file.path = ft_strnew(ft_strlen(file->path) + ft_strlen(arch_name) + 20);
		ft_strcpy(sub_file.path, file->path);
		ft_strcat(sub_file.path, " (architecture ");
		ft_strcat(sub_file.path, arch_name);
		ft_strcat(sub_file.path, ")");
		sub_file.data = file->data + fa->offset;
		sub_file.size = fa->size;
		dump_segments(&sub_file);
		i++;
		free(sub_file.path);
	}
}
