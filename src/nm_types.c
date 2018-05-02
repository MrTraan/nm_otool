/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:07:00 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 17:54:39 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

char	get_char_from_type(t_u8 type)
{
	if (type & N_PEXT)
		return ('c');
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

t_u8	get_sectname_32(t_file *file, int offset, t_u8 k, char *storage)
{
	struct segment_command		*segment;
	struct section				*sect;
	t_u32						j;

	segment = (struct segment_command *)get_off(file, offset);
	if (file->is_swap)
		swap_segment_command(segment, 0);
	j = -1;
	while (++j < segment->nsects)
	{
		sect = (struct section *)get_off(file, offset +
			sizeof(struct segment_command) + j * sizeof(struct section));
		if (file->is_swap)
			swap_section(sect, 1, 0);
		if (ft_strncmp(sect->sectname, SECT_TEXT, 16) == 0)
			storage[k] = 't';
		else if (ft_strncmp(sect->sectname, SECT_DATA, 16) == 0)
			storage[k] = 'd';
		else if (ft_strncmp(sect->sectname, SECT_BSS, 16) == 0)
			storage[k] = 'b';
		else
			storage[k] = 's';
		k++;
	}
	return (k);
}

t_u8	get_sectname_64(t_file *file, int offset, t_u8 k, char *storage)
{
	struct segment_command_64	*segment;
	struct section_64			*sect;
	t_u32						j;

	segment = (struct segment_command_64 *)get_off(file, offset);
	if (file->is_swap)
		swap_segment_command_64(segment, 0);
	j = -1;
	while (++j < segment->nsects)
	{
		sect = (struct section_64 *)get_off(file, offset +
			sizeof(struct segment_command_64) + j * sizeof(struct section_64));
		if (file->is_swap)
			swap_section_64(sect, 1, 0);
		if (ft_strncmp(sect->sectname, SECT_TEXT, 16) == 0)
			storage[k] = 't';
		else if (ft_strncmp(sect->sectname, SECT_DATA, 16) == 0)
			storage[k] = 'd';
		else if (ft_strncmp(sect->sectname, SECT_BSS, 16) == 0)
			storage[k] = 'b';
		else
			storage[k] = 's';
		k++;
	}
	return (k);
}

void	get_sectnames(t_file *file, int offset, t_u32 ncmds, char *storage)
{
	t_u32					i;
	t_u8					k;
	struct load_command		*cmd;

	i = -1;
	k = 0;
	while (++i < ncmds)
	{
		cmd = (struct load_command *)get_off(file, offset);
		if (file->is_swap)
			swap_load_command(cmd, 0);
		if (cmd->cmd == LC_SEGMENT_64)
		{
			k = get_sectname_64(file, offset, k, storage);
			if (file->is_swap)
				swap_load_command(cmd, 0);
		}
		else if (cmd->cmd == LC_SEGMENT)
		{
			k = get_sectname_32(file, offset, k, storage);
			if (file->is_swap)
				swap_load_command(cmd, 0);
		}
		offset += cmd->cmdsize;
	}
}

void	dump_symtab_command(t_file *file,
			struct symtab_command *sc, char *sectnames)
{
	t_list					*print_list;

	print_list = NULL;
	if (file->is_swap)
		swap_symtab_command(sc, 0);
	if (file->is_64)
		browse_nlist64(&print_list, file, sc, sectnames);
	else
		browse_nlist32(&print_list, file, sc, sectnames);
	ft_lstsort(print_list, sort_nmlines_lex);
	ft_lstiter(print_list, print_nmlines_list);
}
