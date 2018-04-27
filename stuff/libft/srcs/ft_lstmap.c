/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:55:48 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/25 18:02:18 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*current;
	t_list	*to_copy;

	if (!lst)
		return (NULL);
	to_copy = (*f)(lst);
	current = ft_lstnew(to_copy->content, to_copy->content_size);
	if (!current)
		return (NULL);
	start = current;
	lst = lst->next;
	while (lst)
	{
		to_copy = (*f)(lst);
		current->next = ft_lstnew(to_copy->content, to_copy->content_size);
		if (!current->next)
			return (NULL);
		current = current->next;
		lst = lst->next;
	}
	return (start);
}
