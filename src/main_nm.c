/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:39:56 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 12:09:06 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>
#include <stdio.h>
#include <ar.h>

void	get_sectnames(t_file *file, int offset, int is_swap, t_u32 ncmds, char *storage)
{
	t_u32		i;
	t_u32		k;

	i = 0;
	k = 0;
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

				if (k < 255)
				{
					if (ft_strncmp(sect->sectname, SECT_TEXT, 16) == 0)
						storage[k] = 't';
					else if (ft_strncmp(sect->sectname, SECT_DATA, 16) == 0)
						storage[k] = 'd';
					else if (ft_strncmp(sect->sectname, SECT_BSS, 16) == 0)
						storage[k] = 'b';
					else if (ft_strncmp(sect->sectname, "__xcrun_shim", 16) == 0)
						storage[k] = 's';
					else
						dprintf("%d: Ignored div %s\n", k, sect->sectname);
					k++;
				}

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

				if (k < 255)
				{
					if (ft_strncmp(sect->sectname, SECT_TEXT, 16) == 0)
						storage[k] = 't';
					else if (ft_strncmp(sect->sectname, SECT_DATA, 16) == 0)
						storage[k] = 'd';
					else if (ft_strncmp(sect->sectname, SECT_BSS, 16) == 0)
						storage[k] = 'b';
					else if (ft_strncmp(sect->sectname, "__xcrun_shim", 16) == 0)
						storage[k] = 's';
					else
						dprintf("%d: Ignored div %s\n", k, sect->sectname);
					k++;
				}

				suboffset += sizeof(struct section);
			}
			if (is_swap)
				swap_load_command(cmd, 0);
		}
		offset += cmd->cmdsize;
		i++;
	}
}

void	print_nmlines_list(t_list *elem)
{
	t_nm_line		*line;

	line = (t_nm_line *)elem->content;
	if (line->symbol == 0)
		return ;
	if (line->is_64)
	{
		if (line->addr == 0)
			ft_printf("%16c %c %s\n", ' ', line->symbol, line->name);
		else
			ft_printf("%016llx %c %s\n", line->addr, line->symbol, line->name);
	}
	else
	{
		if (line->addr == 0)
			ft_printf("%8c %c %s\n", ' ', line->symbol, line->name);
		else
			ft_printf("%08x %c %s\n", line->addr, line->symbol, line->name);
	}
}

int		sort_nmlines_lex(t_list *a, t_list *b)
{
	t_nm_line	*la;
	t_nm_line	*lb;

	la = (t_nm_line *)a->content;
	lb = (t_nm_line *)b->content;
	return (ft_strcmp(la->name, lb->name));
}

char	get_char_from_type(t_u8 type)
{
	if ((type & N_TYPE) == N_UNDF)
		return ('u');
	if ((type & N_TYPE) == N_ABS)
		return ('a');
	if ((type & N_TYPE) == N_PBUD)
		return ('u');
	if ((type & N_TYPE) == N_INDR)
		return ('i');
	return (0);
}

void	browse_nlist64(t_list **print_list, t_file *file, struct symtab_command *sc, char *sectnames)
{
	t_nm_line			line;
	t_u32				i;
	struct nlist_64		*array;

	array = (struct nlist_64 *)(file->data + sc->symoff),
	ft_memset(&line, 0, sizeof(t_nm_line));
	line.is_64 = 1;
	i = 0;
	while (i < sc->nsyms)
	{
		if ((array[i].n_type & N_STAB) && ++i)
			continue ;
		if ((array[i].n_type & N_TYPE) == N_SECT && array[i].n_sect < 255 && array[i].n_sect >= 1)
			line.symbol = sectnames[array[i].n_sect - 1];
		else
			line.symbol = get_char_from_type(array[i].n_type);
		if (array[i].n_type & N_EXT)
			line.symbol -= 32;
		if ((array[i].n_type & N_TYPE) == N_UNDF)
			line.addr = 0;
		else
			line.addr = array[i].n_value;
		line.name = (char *)(file->data + sc->stroff + array[i].n_un.n_strx);
		ft_lstadd(print_list, ft_lstnew(&line, sizeof(t_nm_line)));
		i++;
	}
}

void	browse_nlist32(t_list **print_list, t_file *file, struct symtab_command *sc, char *sectnames)
{
	t_nm_line		line;
	t_u32			i;
	struct nlist	*array;

	array = (struct nlist *)(file->data + sc->symoff),
	ft_memset(&line, 0, sizeof(t_nm_line));
	line.is_64 = 0;
	i = 0;
	while (i < sc->nsyms)
	{
		if (array[i].n_type & N_STAB)
		{
			printf("Ignoring nstab\n");
			i++;
			continue ;
		}
		if ((array[i].n_type & N_TYPE) == N_SECT && array[i].n_sect < 255 && array[i].n_sect >= 1)
			line.symbol = sectnames[array[i].n_sect - 1];
		else
			line.symbol = get_char_from_type(array[i].n_type);
		if (array[i].n_type & N_EXT)
			line.symbol -= 32;
		if ((array[i].n_type & N_TYPE) == N_UNDF)
			line.addr = 0;
		else
			line.addr = array[i].n_value;
		line.name = (char *)(file->data + sc->stroff + array[i].n_un.n_strx);
		ft_lstadd(print_list, ft_lstnew(&line, sizeof(t_nm_line)));
		i++;
	}
}

void	dump_segm_commands(t_file *file, int offset, int is_swap, t_u32 ncmds)
{
	t_u32		i;
	char		sectnames[255];
	t_list		*print_list;

	print_list = NULL;
	ft_memset(sectnames, 0, 255);
	get_sectnames(file, offset, is_swap, ncmds, sectnames);

	i = 0;
	while (i < ncmds)
	{
		struct load_command *cmd = (struct load_command *)(file->data + offset);
		if (is_swap)
			swap_load_command(cmd, 0);
		if (cmd->cmd == LC_SYMTAB)
		{
			struct symtab_command *sc;

			sc = (struct symtab_command *)cmd;
			if (is_swap)
				swap_symtab_command(sc, 0);

			if (file->is_64)
				browse_nlist64(&print_list, file, sc, sectnames);
			else
				browse_nlist32(&print_list, file, sc, sectnames);

			ft_lstsort(print_list, sort_nmlines_lex);
			ft_lstiter(print_list, print_nmlines_list);
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
	file->is_64 = is_64;
	file->is_swap = should_swap;
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