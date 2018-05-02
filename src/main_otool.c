/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:39:56 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 17:47:27 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	dump_segm_commands(t_file *file, int offset, int is_swap, t_u32 ncmds)
{
	t_u32					i;
	struct load_command		*cmd;

	i = 0;
	while (i < ncmds)
	{
		cmd = (struct load_command *)get_off(file, offset);
		if (is_swap)
			swap_load_command(cmd, 0);
		if (cmd->cmd == LC_SEGMENT_64)
		{
			dump_segment64(file, (struct segment_command_64 *)cmd, offset);
			if (file->is_swap)
				swap_load_command(cmd, 0);
		}
		else if (cmd->cmd == LC_SEGMENT)
		{
			dump_segment(file, (struct segment_command *)cmd, offset);
			if (file->is_swap)
				swap_load_command(cmd, 0);
		}
		offset += cmd->cmdsize;
		i++;
	}
}

void	dump_mach_header(t_file *file, int offset, int is_swap)
{
	struct mach_header	*mh;

	mh = (struct mach_header *)(file->data + offset);
	if (is_swap)
		swap_mach_header(mh, 0);
	dump_segm_commands(file, offset + sizeof(struct mach_header),
			is_swap, mh->ncmds);
}

void	dump_mach_header_64(t_file *file, int offset, int is_swap)
{
	struct mach_header_64	*mh;

	mh = (struct mach_header_64 *)(file->data + offset);
	if (is_swap)
		swap_mach_header_64(mh, 0);
	dump_segm_commands(file, offset + sizeof(struct mach_header_64),
			is_swap, mh->ncmds);
}

int		dump_segments(t_file *file)
{
	t_u32	magic;
	int		should_swap;

	if (file->size > SARMAG && ft_strncmp(file->data, ARMAG, SARMAG) == 0)
	{
		handle_archive_otool(file);
		return (0);
	}
	magic = read_magic(file->data, 0);
	if (!is_magic_ok(magic))
		return (mt_store_error(MT_ERRNO_OBJ, file->path));
	should_swap = should_swap_bytes(magic);
	file->is_swap = should_swap;
	if (is_fat_magic(magic))
	{
		handle_fat_otool(file, magic, should_swap);
		return (0);
	}
	file->is_64 = is_magic_64(magic);
	if (file->is_64)
		dump_mach_header_64(file, 0, should_swap);
	else
		dump_mach_header(file, 0, should_swap);
	return (0);
}

int		main(int ac, char **av)
{
	t_file		file;
	int			i;

	file.is_ppc = 0;
	if (ac < 2)
	{
		mt_store_error(MT_ERRNO_NO_ARGUMENT, "");
		return (mt_perror());
	}
	i = 1;
	while (i < ac)
	{
		file.path = av[i];
		if (map_file(&file) != 0)
			return (mt_perror());
		if (dump_segments(&file) != 0)
			return (mt_perror());
		unmap_file(&file);
		i++;
	}
	return (0);
}
