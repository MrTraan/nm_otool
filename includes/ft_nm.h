/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:42:14 by ngrasset          #+#    #+#             */
/*   Updated: 2018/04/27 14:49:57 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <libft.h>
# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/swap.h>
# include <stdio.h>
# include <ft_printf.h>

// # define dprintf(...) ft_printf(__VA_ARGS__)
# define dprintf(...) fprintf(stderr, __VA_ARGS__)

# define MT_ERRNO_MEMORY		1
# define MT_ERRNO_OPEN_FILE		2
# define MT_ERRNO_NO_ARGUMENT	3
# define MT_ERRNO_FSTAT			4


typedef unsigned char		t_u8;
typedef unsigned short		t_u16;
typedef unsigned int		t_u32;
typedef unsigned long long	t_u64;

typedef char				t_s8;
typedef short				t_s16;
typedef int					t_s32;
typedef long long			t_s64;

typedef struct mach_header	t_mh;
typedef struct mach_header_64	t_mh64;

typedef struct				s_file
{
	char					*data;
	size_t					size;
	char					*path;
}							t_file;

typedef struct				s_cpu_type_names
{
	cpu_type_t				cpu_type;
	const char				*name;
}							t_cpu_type_names;

typedef struct				s_u32tos
{
	t_u32					value;
	const char				*name;
}							t_u32tos;

int							mt_store_error(int errno, char *msg);
int							mt_perror();

int							map_file(t_file *file);
int							unmap_file(t_file *file);

t_u32						read_magic(void *file, int offset);
int							is_magic_64(t_u32 magic);
int							should_swap_bytes(t_u32 magic);

int							is_fat_magic(t_u32 magic);

void						print_mach_header(struct mach_header *mh);
void						print_mach_header64(struct mach_header_64 *mh);

#endif