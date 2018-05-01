/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:39:56 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/01 15:42:08 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>
#include <stdio.h>
#include <ar.h>

void	dump_text_section64(t_file *file, struct section_64 *sect)
{
	t_u32 offset = sect->offset;
	t_u32 i = 0;

	ft_printf("%s:\nContents of (__TEXT,__text) section\n", file->path);
	while (i < sect->size)
	{
		ft_printf("%016llx\t", sect->addr + i);
		for (t_u32 j = 0; j < 16 && (i + (j * sizeof(t_u8))) < sect->size; j++)
		{
			t_u8 *c = (t_u8 *)(file->data + offset + i + (j * sizeof(t_u8)));
			ft_printf("%02x ", *c);
		}
		ft_printf("\n");
		i += 16 * sizeof(t_u8);
	}
}

void	dump_text_section(t_file *file, struct section *sect)
{
	t_u32 offset = sect->offset;
	t_u32 i = 0;

	ft_printf("%s:\nContents of (__TEXT,__text) section\n", file->path);
	while (i < sect->size)
	{
		ft_printf("%08x\t", sect->addr + i);
		for (t_u32 j = 0; j < 16 && (i + (j * sizeof(t_u8))) < sect->size; j++)
		{
			t_u8 *c = (t_u8 *)(file->data + offset + i + (j * sizeof(t_u8)));
			ft_printf("%02x ", *c);
		}
		ft_printf("\n");
		i += 16 * sizeof(t_u8);
	}
}


void	dump_segm_commands(t_file *file, int offset, int is_swap, t_u32 ncmds)
{
	t_u32	i;

	i = 0;
	while (i < ncmds)
	{
		struct load_command *cmd = (struct load_command *)(file->data + offset);
		if (is_swap)
			swap_load_command(cmd, 0);
		if (cmd->cmd == LC_SEGMENT_64)
		{
			struct segment_command_64 *segment = (struct segment_command_64 *)
				(file->data + offset);
			if (is_swap)
				swap_segment_command_64(segment, 0);

			int suboffset = offset + sizeof(struct segment_command_64);
			for (t_u32 j = 0; j < segment->nsects; j++) {
				struct section_64 *sect = (struct section_64 *)(file->data + suboffset);

				if (is_swap)
					swap_section_64(sect, 1, 0);
				if (ft_strcmp(sect->sectname, "__text") == 0)
					dump_text_section64(file, sect);

				suboffset += sizeof(struct section_64);
			}
			if (is_swap)
				swap_load_command(cmd, 0);
		}

		if (cmd->cmd == LC_SEGMENT)
		{
			struct segment_command *segment = (struct segment_command *)
				(file->data + offset);
			if (is_swap)
				swap_segment_command(segment, 0);
			
			int suboffset = offset + sizeof(struct segment_command);
			for (t_u32 j = 0; j < segment->nsects; j++) {
				struct section *sect = (struct section *)(file->data + suboffset);
				if (is_swap)
					swap_section(sect, 1, 0);

				if (ft_strcmp(sect->sectname, "__text") == 0)
					dump_text_section(file, sect);

				suboffset += sizeof(struct section);
			}
			if (is_swap)
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
	print_mach_header(mh);
	dump_segm_commands(file, offset + sizeof(struct mach_header), is_swap, mh->ncmds);
}

void	dump_mach_header_64(t_file *file, int offset, int is_swap)
{
	struct mach_header_64	*mh;

	mh = (struct mach_header_64 *)(file->data + offset);
	if (is_swap)
		swap_mach_header_64(mh, 0);
	print_mach_header64(mh);
	dump_segm_commands(file, offset + sizeof(struct mach_header_64), is_swap, mh->ncmds);
}

int		dump_segments(t_file *file)
{
	t_u32	magic;
	int		is_64;
	int		should_swap;

	if (file->size > SARMAG && ft_strncmp(file->data, ARMAG, SARMAG) == 0)
	{
		// todo
		handle_archive(file);
		return (0);
	}
	magic = read_magic(file->data, 0);
	if (!is_magic_ok(magic))
		return mt_store_error(MT_ERRNO_OBJ, file->path);
	should_swap = should_swap_bytes(magic);
	if (is_fat_magic(magic))
	{
		// todo
		handle_fat(file, magic, should_swap);
		return (0);
	}
	is_64 = is_magic_64(magic);
	if (is_64)
		dump_mach_header_64(file, 0, should_swap);
	else
		dump_mach_header(file, 0, should_swap);
	return (0);
}

int		main(int ac, char **av)
{
	t_file		file;
	int			i;

	if (ac < 2)
	{
		mt_store_error(MT_ERRNO_NO_ARGUMENT, "");
		return mt_perror();
	}
	i = 1;
	while (i < ac)
	{
		file.path = av[i];
		if (map_file(&file) != 0)
			return mt_perror();
		if (dump_segments(&file) != 0)
			return mt_perror();
		unmap_file(&file);
		i++;
	}
	return (0);
}
