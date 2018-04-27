/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:38:51 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/25 17:50:59 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst)
		return ;
	if (*alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
	}
	*alst = NULL;
}
