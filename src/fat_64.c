/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:06:53 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 18:26:51 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		is_fat_64(t_u32 magic)
{
	return (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64);
}

char	*get_fat64_filename(t_file *file, struct fat_arch_64 *fa)
{
	char			*res;
	const char		*arch_name;

	if (fa->cputype == CPU_TYPE_POWERPC64)
		file->is_ppc = 1;
	else
		file->is_ppc = 0;
	arch_name = get_cpu_name(fa->cputype);
	if (!arch_name)
		return (ft_strdup("Unkown"));
	res = ft_strnew(ft_strlen(file->path) +
			ft_strlen(arch_name) + 20);
	ft_strcpy(res, file->path);
	ft_strcat(res, " (architecture ");
	ft_strcat(res, arch_name);
	ft_strcat(res, ")");
	return (res);
}

int		fat_default_arch64(t_file *file, struct fat_header *fh)
{
	t_u32				i;
	t_file				sub_file;
	struct fat_arch_64	*fa;

	i = 0;
	while (i < fh->nfat_arch)
	{
		fa = (struct fat_arch_64 *)get_off(file,
				sizeof(struct fat_header) + i * sizeof(struct fat_arch_64));
		if (file->is_swap)
			swap_fat_arch_64(fa, 1, 0);
		if (fa->cputype == CPU_TYPE_X86_64 || fh->nfat_arch == 1)
		{
			sub_file.path = file->path;
			sub_file.data = file->data + fa->offset;
			sub_file.size = fa->size;
			dump_segments(&sub_file);
			return (1);
		}
		i++;
	}
	return (0);
}

void	handle_fat_64(t_file *file, t_u32 magic, int should_swap)
{
	struct fat_header	*fh;
	struct fat_arch_64	*fa;
	t_file				sub_file;
	t_u32				i;

	(void)magic;
	fh = (struct fat_header *)(file->data);
	if (should_swap)
		swap_fat_header(fh, 0);
	if (fat_default_arch64(file, fh))
		return ;
	i = 0;
	while (i < fh->nfat_arch)
	{
		fa = (struct fat_arch_64 *)get_off(file,
				sizeof(struct fat_header) + i * sizeof(struct fat_arch_64));
		sub_file.path = get_fat64_filename(file, fa);
		sub_file.data = file->data + fa->offset;
		sub_file.size = fa->size;
		dump_segments(&sub_file);
		i++;
		free(sub_file.path);
	}
}
