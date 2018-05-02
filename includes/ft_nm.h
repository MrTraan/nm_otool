/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:42:14 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 18:40:41 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <libft.h>
# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/swap.h>
# include <mach-o/nlist.h>
# include <ft_printf.h>
# include <ar.h>

# define MT_ERRNO_MEMORY		1
# define MT_ERRNO_OPEN_FILE		2
# define MT_ERRNO_NO_ARGUMENT	3
# define MT_ERRNO_FSTAT			4
# define MT_ERRNO_OBJ			5
# define MT_ERRNO_MMAP			6
# define DEFAULT_PATH			"a.out"

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
	char					is_swap;
	char					is_64;
	char					is_ppc;
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

typedef struct				s_nm_line
{
	int						is_64;
	int						is_undef;
	t_u64					addr;
	char					symbol;
	char					*name;
}							t_nm_line;

int							mt_store_error(int errno, char *msg);
int							mt_perror();

int							dump_segments(t_file *file);

int							map_file(t_file *file);
int							unmap_file(t_file *file);

t_u32						read_magic(void *file, int offset);
int							is_magic_64(t_u32 magic);
int							should_swap_bytes(t_u32 magic);
int							is_magic_ok(t_u32 magic);

int							is_fat_magic(t_u32 magic);
int							is_fat_64(t_u32 magic);

void						handle_archive_otool(t_file *file);
void						handle_archive_nm(t_file *file);
void						handle_fat_nm(t_file *file,
								t_u32 magic, int shouap);
void						handle_fat_otool(t_file *file,
								t_u32 magic, int shouap);
void						handle_fat_64(t_file *file,
								t_u32 magic, int shouap);

const char					*get_cpu_name(cpu_type_t cpu);
const char					*get_magic_name(t_u32 magic);

void						get_sectnames(t_file *file, int offset,
								t_u32 ncmds, char *storage);

void						*get_off(t_file *file, size_t offset);

void						browse_nlist64(t_list **print_list, t_file *file,
								struct symtab_command *sc, char *sectnames);
void						browse_nlist32(t_list **print_list, t_file *file,
								struct symtab_command *sc, char *sectnames);

char						get_char_from_type(t_u8 type);
void						get_sectnames(t_file *file, int offset,
								t_u32 ncmds, char *storage);

void						print_nmlines_list(t_list *elem);
int							sort_nmlines_lex(t_list *a, t_list *b);

void						dump_text_section(t_file *file,
								struct section *sect);
void						dump_text_section64(t_file *file,
								struct section_64 *sect);

void						dump_segment(t_file *file,
								struct segment_command *segment, size_t offset);
void						dump_segment64(t_file *file,
							struct segment_command_64 *segment, size_t offset);

void						dump_symtab_command(t_file *file,
								struct symtab_command *sc, char *sectnames);

#endif
