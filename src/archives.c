/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archives.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 12:37:06 by ngrasset          #+#    #+#             */
/*   Updated: 2018/04/28 12:46:44 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>
#include <ar.h>

int		get_archive_size(char *size)
{
	char	bo_size[11];

	ft_strncpy(bo_size, size, 10);
	bo_size[10] = '\0';
	return (ft_atoi(bo_size));
}

int		get_archive_name_size(char *name)
{
	int		x;
	char	*word;

	word = ft_strchr(name, '/') + 1;
	x = ft_atoi(word);
	return (x);
}

void	handle_archive(t_file *file)
{
	struct ar_hdr	*hdr;
	struct ar_hdr	*o_ptr;
	int				size;
	int				header_size;
	int				name_size;
	t_file			sub_file;
	size_t			offset;

	ft_printf("Archive : %s\n", file->path);
	hdr = (struct ar_hdr *)(file->data + SARMAG);
	header_size = get_archive_size(hdr->ar_size);

	offset = sizeof(struct ar_hdr) + header_size;

	while (offset < file->size - SARMAG)
	{
		o_ptr = (struct ar_hdr *)((void *)hdr + offset);
		size = get_archive_size(o_ptr->ar_size);
		name_size = get_archive_name_size(o_ptr->ar_name);

		sub_file.path = ft_strnew(name_size + ft_strlen(file->path) + 3);
		ft_strcpy(sub_file.path, file->path);
		ft_strcat(sub_file.path, "(");
		ft_strncat(sub_file.path, (char *)((void *)o_ptr + sizeof(struct ar_hdr)), name_size);
		ft_strcat(sub_file.path, ")");
		sub_file.size = size - name_size;
		sub_file.data = (void *)o_ptr + sizeof(struct ar_hdr) + name_size;
		dump_segments(&sub_file);

		free(sub_file.path);
		offset += sizeof(struct ar_hdr) + size;
	}
}

