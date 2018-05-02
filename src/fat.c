/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:03:10 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 18:29:44 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		fat_default_arch_nm(t_file *file, struct fat_header *fh)
{
	t_u32				i;
	t_file				sub_file;
	struct fat_arch		*fa;

	i = 0;
	while (i < fh->nfat_arch)
	{
		fa = (struct fat_arch *)get_off(file,
				sizeof(struct fat_header) + i * sizeof(struct fat_arch));
		if (file->is_swap)
			swap_fat_arch(fa, 1, 0);
		if (fa->cputype == CPU_TYPE_X86_64 || fh->nfat_arch == 1)
		{
			if (fh->nfat_arch == 1)
				ft_printf("%s:\n", file->path);
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

int		fat_default_arch(t_file *file, struct fat_header *fh)
{
	t_u32				i;
	t_file				sub_file;
	struct fat_arch		*fa;

	i = 0;
	while (i < fh->nfat_arch)
	{
		fa = (struct fat_arch *)get_off(file,
				sizeof(struct fat_header) + i * sizeof(struct fat_arch));
		if (file->is_swap)
			swap_fat_arch(fa, 1, 0);
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

char	*get_fat_filename(t_file *file, struct fat_arch *fa)
{
	char			*res;
	const char		*arch_name;

	if (fa->cputype == CPU_TYPE_POWERPC)
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

void	handle_fat_otool(t_file *file, t_u32 magic, int should_swap)
{
	struct fat_header	*fh;
	struct fat_arch		*fa;
	t_file				sub_file;
	t_u32				i;

	if (is_fat_64(magic))
		return ((void)handle_fat_64(file, magic, should_swap));
	fh = (struct fat_header *)(file->data);
	if (should_swap)
		swap_fat_header(fh, 0);
	if (fat_default_arch(file, fh))
		return ;
	i = -1;
	while (++i < fh->nfat_arch)
	{
		fa = (struct fat_arch *)get_off(file,
				sizeof(struct fat_header) + i * sizeof(struct fat_arch));
		get_off(file, fa->offset + 1);
		sub_file.path = get_fat_filename(file, fa);
		sub_file.is_ppc = file->is_ppc;
		sub_file.data = file->data + fa->offset;
		sub_file.size = fa->size;
		dump_segments(&sub_file);
		free(sub_file.path);
	}
}

void	handle_fat_nm(t_file *file, t_u32 magic, int should_swap)
{
	struct fat_header	*fh;
	struct fat_arch		*fa;
	t_file				sub_file;
	t_u32				i;

	if (is_fat_64(magic))
		return ((void)handle_fat_64(file, magic, should_swap));
	fh = (struct fat_header *)(file->data);
	if (should_swap)
		swap_fat_header(fh, 0);
	if (fat_default_arch_nm(file, fh))
		return ;
	i = 0;
	while (i < fh->nfat_arch)
	{
		fa = (struct fat_arch *)get_off(file,
				sizeof(struct fat_header) + i * sizeof(struct fat_arch));
		get_off(file, fa->offset + 1);
		ft_printf("\n%s (for architecture %s):\n",
				file->path, get_cpu_name(fa->cputype));
		sub_file.data = file->data + fa->offset;
		sub_file.size = fa->size;
		dump_segments(&sub_file);
		i++;
	}
}
