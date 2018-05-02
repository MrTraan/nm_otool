/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_nlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:05:13 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 17:29:23 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	save_nlist(struct nlist *nl, t_nm_line *line, char *sectnames)
{
	if ((nl->n_type & N_TYPE) == N_SECT && nl->n_sect < 255 && nl->n_sect >= 1)
		line->symbol = sectnames[nl->n_sect - 1];
	else
		line->symbol = get_char_from_type(nl->n_type);
	if (nl->n_type & N_EXT)
		line->symbol -= 32;
	if ((nl->n_type & N_TYPE) == N_UNDF && !(nl->n_type & N_PEXT))
		line->is_undef = 1;
	else
	{
		line->is_undef = 0;
		line->addr = nl->n_value;
	}
}

void	save_nlist64(struct nlist_64 *nl, t_nm_line *line, char *sectnames)
{
	if ((nl->n_type & N_TYPE) == N_SECT && nl->n_sect < 255 && nl->n_sect >= 1)
		line->symbol = sectnames[nl->n_sect - 1];
	else
		line->symbol = get_char_from_type(nl->n_type);
	if (nl->n_type & N_EXT)
		line->symbol -= 32;
	if ((nl->n_type & N_TYPE) == N_UNDF && !(nl->n_type & N_PEXT))
		line->is_undef = 1;
	else
	{
		line->is_undef = 0;
		line->addr = nl->n_value;
	}
}

void	browse_nlist64(t_list **print_list, t_file *file,
			struct symtab_command *sc, char *sectnames)
{
	t_nm_line			line;
	t_u32				i;
	struct nlist_64		*nl;

	ft_memset(&line, 0, sizeof(t_nm_line));
	line.is_64 = 1;
	i = 0;
	while (i < sc->nsyms)
	{
		nl = (struct nlist_64 *)get_off(file,
				sc->symoff + i * sizeof(struct nlist_64));
		if (file->is_swap)
			swap_nlist_64(nl, 1, 0);
		if ((nl->n_type & N_STAB) && ++i)
			continue ;
		save_nlist64(nl, &line, sectnames);
		line.name = (char *)get_off(file, sc->stroff + nl->n_un.n_strx);
		ft_lstadd(print_list, ft_lstnew(&line, sizeof(t_nm_line)));
		i++;
	}
}

void	browse_nlist32(t_list **print_list, t_file *file,
			struct symtab_command *sc, char *sectnames)
{
	t_nm_line		line;
	t_u32			i;
	struct nlist	*nl;

	ft_memset(&line, 0, sizeof(t_nm_line));
	line.is_64 = 0;
	i = 0;
	while (i < sc->nsyms)
	{
		nl = (struct nlist *)get_off(file,
				sc->symoff + i * sizeof(struct nlist));
		if (file->is_swap)
			swap_nlist(nl, 1, 0);
		if ((nl->n_type & N_STAB) && ++i)
			continue ;
		save_nlist(nl, &line, sectnames);
		line.name = (char *)get_off(file, sc->stroff + nl->n_un.n_strx);
		ft_lstadd(print_list, ft_lstnew(&line, sizeof(t_nm_line)));
		i++;
	}
}
