/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:06:25 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 21:43:08 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	while (*uc_s1)
	{
		if (*uc_s1 != *uc_s2)
			return ((int)(*uc_s1 - *uc_s2));
		uc_s1++;
		uc_s2++;
	}
	return ((int)(*uc_s1 - *uc_s2));
}
