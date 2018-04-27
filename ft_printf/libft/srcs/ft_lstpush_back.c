/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:56:31 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/27 14:39:24 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (!new)
		return ;
	if (!alst)
		return ;
	cur = *alst;
	if (!cur)
	{
		*alst = new;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
