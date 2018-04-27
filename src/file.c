/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:46:36 by ngrasset          #+#    #+#             */
/*   Updated: 2018/04/25 15:10:18 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <string.h>

int				map_file(t_file *file)
{
	int				fd;
	void			*ptr;
	struct stat		stats;

	if ((fd = open(file->path, O_RDONLY)) < 0)
		return mt_store_error(MT_ERRNO_OPEN_FILE, file->path);
	if (fstat(fd, &stats) < 0)
		return mt_store_error(MT_ERRNO_FSTAT, strerror(errno));
	if ((ptr = mmap(0, stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return mt_store_error(MT_ERRNO_MEMORY, strerror(errno));
	file->data = (char *)ptr;
	file->size = stats.st_size;
	close(fd);
	return (0);
}

int				unmap_file(t_file *file)
{
	return (munmap((void *)(file->data), file->size));
}
