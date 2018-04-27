/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:20:44 by ngrasset          #+#    #+#             */
/*   Updated: 2016/01/06 11:00:43 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_delstrtab(char **tab)
{
	char	**start;

	if (!tab)
		return ;
	start = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(start);
}
