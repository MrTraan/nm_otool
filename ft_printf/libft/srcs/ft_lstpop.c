/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:09:48 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/13 14:15:41 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstpop(t_list **head)
{
	t_list	*cur;
	t_list	*previous;

	if (!*head)
		return (NULL);
	if (!(*head)->next)
	{
		cur = *head;
		*head = NULL;
		return (cur);
	}
	cur = (*head)->next;
	previous = *head;
	while (cur->next)
	{
		previous = cur;
		cur = cur->next;
	}
	previous->next = NULL;
	return (cur);
}
