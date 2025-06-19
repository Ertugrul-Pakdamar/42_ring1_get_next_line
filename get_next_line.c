/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:41 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/19 22:19:04 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * 
 * TODO:
 * read durmuyor
 * hiç static var kullanmadım
 * tahminen realloc yazacağım
 * 
 * NOTE:
 * text test amaçlıdır
 * get_next_line.h da prototip unuttum
 * main var
 * *_utils.c ne işe yarıyor acaba
 */

static void	read_after_newline(int fd, int i, char **stat_s, char c)
{
	int	j;

	j = i;
	while (read(fd, &c, 1) && j < BUFFER_SIZE)
	{
		(*stat_s)[j - i] = c;
		j++;
	}
}

// ret0 => no newline | ret_else => newline
static int	check_static(char **stat_s, char **res)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < BUFFER_SIZE && (*stat_s)[i])
	{
		if ((*stat_s)[i] != '\n')
			(*res)[i] = (*stat_s)[i];
		else
		{
			(*stat_s) = &(*stat_s)[i + 1];
			ret = 1;
			break ;
		}
		i++;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*stat_s;
	char		c;
	int			i;

	res = (char *)ft_calloc(2, 1);
	if (!stat_s)
		stat_s = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (check_static(&stat_s, &res) != 0)
		return (res);
	i = ft_strlen(stat_s);
	while (read(fd, &c, 1))
	{
		if (c != '\n')
			res[i] = c;
		else
		{
			read_after_newline(fd, i, &stat_s, c);
			break ;
		}
		i++;
		res = (char *)ft_realloc((char *)res, i, i + 1);
	}
	return (res);
}
