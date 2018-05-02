/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:17 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 15:10:55 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	print_nmlines_list(t_list *elem)
{
	t_nm_line		*line;

	line = (t_nm_line *)elem->content;
	if (line->symbol == 0)
		return ;
	if (line->is_64)
	{
		if (line->is_undef)
			ft_printf("%16c %c %s\n", ' ', line->symbol, line->name);
		else
			ft_printf("%016llx %c %s\n", line->addr, line->symbol, line->name);
	}
	else
	{
		if (line->is_undef)
			ft_printf("%8c %c %s\n", ' ', line->symbol, line->name);
		else
			ft_printf("%08llx %c %s\n", line->addr, line->symbol, line->name);
	}
}

int		sort_nmlines_lex(t_list *a, t_list *b)
{
	t_nm_line	*la;
	t_nm_line	*lb;
	int			diff;

	la = (t_nm_line *)a->content;
	lb = (t_nm_line *)b->content;
	diff = ft_strcmp(la->name, lb->name);
	if (diff == 0 && la->is_undef)
		return (-1);
	if (diff == 0 && lb->is_undef)
		return (1);
	if (diff == 0)
		return (la->addr > lb->addr ? 1 : -1);
	return (diff);
}
