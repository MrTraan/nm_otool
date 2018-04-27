/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_delim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:41:45 by ngrasset          #+#    #+#             */
/*   Updated: 2016/01/05 19:24:52 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_delim(char *s1, char *s2, char *delim)
{
	char	*step1;
	char	*step2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strjoin(delim, s2));
	if (!s2)
		return (ft_strjoin(s1, delim));
	step1 = ft_strjoin(s1, delim);
	if (!step1)
		return (NULL);
	step2 = ft_strjoin(step1, s2);
	free(step1);
	return (step2);
}
