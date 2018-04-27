/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:57:09 by ngrasset          #+#    #+#             */
/*   Updated: 2016/02/02 00:59:59 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*mem_concat(char *dst, char *src)
{
	char	*res;

	if (!dst)
	{
		dst = ft_strdup(src);
		return (dst);
	}
	res = ft_strnew(ft_strlen(dst) + ft_strlen(src) + 1);
	if (!res)
		return (NULL);
	res = ft_strcpy(res, dst);
	res = ft_strcat(res, src);
	free(dst);
	dst = res;
	return (res);
}

int		get_overf(char **line, char *overflow)
{
	char	*endl;

	endl = ft_strchr(overflow, '\n');
	if (endl)
	{
		*endl = '\0';
		*line = ft_strdup(overflow);
		ft_memmove(overflow, endl + 1, BUFF_SIZE - (endl - overflow));
		return (1);
	}
	*line = ft_strdup(overflow);
	ft_memset(overflow, 0, BUFF_SIZE + 1);
	return (0);
}

int		get_next_buffer(char **line, char *overflow, int fd)
{
	int		ret;
	char	*endl;
	char	buffer[BUFF_SIZE + 1];

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		endl = ft_strchr(buffer, '\n');
		if (endl)
		{
			*endl = '\0';
			*line = mem_concat(*line, buffer);
			ft_strcpy(overflow, endl + 1);
			return (1);
		}
		*line = mem_concat(*line, buffer);
	}
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	static char			overf[MAX_FD][BUFF_SIZE + 1];
	int					ret;

	if (fd < 0 || fd > MAX_FD || !line)
		return (-1);
	*line = NULL;
	if (overf[fd][0])
	{
		ret = get_overf(line, overf[fd]);
		if (ret != 0)
			return (ret);
	}
	ret = get_next_buffer(line, overf[fd], fd);
	if (ret == -1)
		return (-1);
	return (*line != NULL);
}
