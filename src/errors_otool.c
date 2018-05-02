/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_otool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:20:14 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 18:37:40 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>
#include <stdio.h>

static char		g_mt_error_buffer[100] = "";
static int		g_mt_errno = 0;

int				mt_store_error(int errno, char *msg)
{
	if (errno == MT_ERRNO_MEMORY)
		sprintf(g_mt_error_buffer, "Could not allocate memory.%s\n", msg);
	if (errno == MT_ERRNO_OPEN_FILE)
		sprintf(g_mt_error_buffer, "Could not open file: %s\n", msg);
	if (errno == MT_ERRNO_NO_ARGUMENT)
		sprintf(g_mt_error_buffer,
				"First argument must be a file name.%s\n", msg);
	if (errno == MT_ERRNO_FSTAT)
		sprintf(g_mt_error_buffer, "fstat error: %s\n", msg);
	if (errno == MT_ERRNO_OBJ)
		sprintf(g_mt_error_buffer, "%s: is not an object file\n", msg);
	if (errno == MT_ERRNO_MMAP)
		sprintf(g_mt_error_buffer, "Could not mmap file: %s\n", msg);
	g_mt_errno = errno;
	return (errno);
}

int				mt_perror(void)
{
	ft_putstr_fd("ft_otool error: ", 2);
	ft_putstr_fd(g_mt_error_buffer, 2);
	return (g_mt_errno);
}
