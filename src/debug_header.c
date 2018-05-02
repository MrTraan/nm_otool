/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:26:16 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 17:08:07 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

static t_cpu_type_names		g_cpu_names[] = {
	{ CPU_TYPE_I386, "i386" },
	{ CPU_TYPE_X86_64, "x86_64" },
	{ CPU_TYPE_ARM, "arm" },
	{ CPU_TYPE_ARM64, "arm64" },
	{ CPU_TYPE_MC98000, "mc98000" },
	{ CPU_TYPE_POWERPC, "ppc" },
	{ CPU_TYPE_POWERPC64, "ppc64" },
};

static t_u32tos				g_magic_names[] = {
	{ MH_CIGAM, "MH_CIGAM" },
	{ MH_CIGAM_64, "MH_CIGAM_64" },
	{ MH_MAGIC, "MH_MAGIC" },
	{ MH_MAGIC_64, "MH_MAGIC_64" },
	{ FAT_MAGIC, "FAT_MAGIC" },
	{ FAT_CIGAM, "FAT_CIGAM" },
};

static t_u32tos				g_filetype_names[] = {
	{ MH_OBJECT, "MH_OBJECT" },
	{ MH_EXECUTE, "MH_EXECUTE" },
	{ MH_FVMLIB, "MH_FVMLIB" },
	{ MH_CORE, "MH_CORE" },
	{ MH_PRELOAD, "MH_PRELOAD" },
	{ MH_DYLIB, "MH_DYLIB" },
	{ MH_DYLINKER, "MH_DYLINKER" },
	{ MH_BUNDLE, "MH_BUNDLE" },
	{ MH_DYLIB_STUB, "MH_DYLIB_STUB" },
	{ MH_DSYM, "MH_DSYM" },
	{ MH_KEXT_BUNDLE, "MH_KEXT_BUNDLE" },
};

const char	*get_cpu_name(cpu_type_t cpu)
{
	static int	size = sizeof(g_cpu_names) / sizeof(t_cpu_type_names);
	int			i;

	i = 0;
	while (i < size)
	{
		if (g_cpu_names[i].cpu_type == cpu)
			return (g_cpu_names[i].name);
		i++;
	}
	return (NULL);
}

const char	*get_magic_name(t_u32 magic)
{
	static int	magic_names_size = sizeof(g_magic_names) / sizeof(t_u32tos);
	int			i;

	i = 0;
	while (i < magic_names_size)
	{
		if (g_magic_names[i].value == magic)
			return (g_magic_names[i].name);
		i++;
	}
	return (NULL);
}

const char	*get_filetype_name(t_u32 ft)
{
	static int	ft_names_size = sizeof(g_filetype_names) / sizeof(t_u32tos);
	int			i;

	i = 0;
	while (i < ft_names_size)
	{
		if (g_filetype_names[i].value == ft)
			return (g_filetype_names[i].name);
		i++;
	}
	return (NULL);
}
