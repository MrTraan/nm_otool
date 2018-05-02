/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:30:47 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 17:50:13 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	dump_text_section64(t_file *file, struct section_64 *sect)
{
	t_u32	offset;
	t_u32	i;
	t_u32	j;
	t_u8	*c;

	offset = sect->offset;
	i = 0;
	ft_printf("%s:\nContents of (__TEXT,__text) section\n", file->path);
	while (i < sect->size)
	{
		ft_printf("%016llx\t", sect->addr + i);
		j = 0;
		while (j < 16 && (i + (j * sizeof(t_u8))) < sect->size)
		{
			c = (t_u8 *)get_off(file, offset + i + (j * sizeof(t_u8)));
			ft_printf("%02x ", *c);
			j++;
		}
		ft_printf("\n");
		i += 16 * sizeof(t_u8);
	}
}

void	dump_text_section(t_file *file, struct section *sect)
{
	t_u32	offset;
	t_u32	i;
	t_u32	j;
	t_u8	*c;

	offset = sect->offset;
	i = 0;
	ft_printf("%s:\nContents of (__TEXT,__text) section\n", file->path);
	while (i < sect->size)
	{
		ft_printf("%08x\t", sect->addr + i);
		j = 0;
		while (j < 16 && (i + (j * sizeof(t_u8))) < sect->size)
		{
			c = (t_u8 *)get_off(file, offset + i + (j * sizeof(t_u8)));
			if (file->is_ppc && (j + 1) % 4 != 0)
				ft_printf("%02x", *c);
			else
				ft_printf("%02x ", *c);
			j++;
		}
		ft_printf("\n");
		i += 16 * sizeof(t_u8);
	}
}

void	dump_segment64(t_file *file,
			struct segment_command_64 *segment, size_t offset)
{
	size_t				suboffset;
	t_u32				j;
	struct section_64	*sect;

	if (file->is_swap)
		swap_segment_command_64(segment, 0);
	suboffset = offset + sizeof(struct segment_command_64);
	j = 0;
	while (j < segment->nsects)
	{
		sect = (struct section_64 *)get_off(file, suboffset);
		if (file->is_swap)
			swap_section_64(sect, 1, 0);
		if (ft_strncmp(sect->sectname, "__text", 16) == 0)
			dump_text_section64(file, sect);
		suboffset += sizeof(struct section_64);
		j++;
	}
}

void	dump_segment(t_file *file,
			struct segment_command *segment, size_t offset)
{
	size_t			suboffset;
	t_u32			j;
	struct section	*sect;

	if (file->is_swap)
		swap_segment_command(segment, 0);
	suboffset = offset + sizeof(struct segment_command);
	j = 0;
	while (j < segment->nsects)
	{
		sect = (struct section *)get_off(file, suboffset);
		if (file->is_swap)
			swap_section(sect, 1, 0);
		if (ft_strncmp(sect->sectname, "__text", 16) == 0)
			dump_text_section(file, sect);
		suboffset += sizeof(struct section);
		j++;
	}
}
