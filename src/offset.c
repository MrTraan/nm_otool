/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:05:46 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 14:17:03 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	*get_off(t_file *file, size_t offset)
{
	if (offset >= file->size)
	{
		ft_putstr_fd(file->path, 2);
		ft_putstr_fd(" truncacted or malformed object\n", 2);
		unmap_file(file);
		exit(1);
	}
	return (file->data + offset);
}
