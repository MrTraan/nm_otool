/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:23:34 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/25 17:38:27 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_kid;

	new_kid = (t_list *)malloc(sizeof(t_list));
	if (!new_kid)
		return (NULL);
	if (!content)
	{
		new_kid->content = NULL;
		new_kid->content_size = 0;
	}
	else
	{
		new_kid->content = (void *)malloc(content_size);
		if (!new_kid->content)
			return (NULL);
		ft_memcpy(new_kid->content, content, content_size);
		new_kid->content_size = content_size;
	}
	new_kid->next = NULL;
	return (new_kid);
}
