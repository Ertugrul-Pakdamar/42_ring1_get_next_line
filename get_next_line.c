/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:41 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/19 16:23:41 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*check_static(char **stat_s)
{
	char	*res;
	int		i;

	res = (char *)ft_calloc(BUFFER_SIZE, sizeof(1));
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (stat_s[i] != '\n')
			res[i] = (*stat_s)[i];
		else
		{
			*stat_s = (*stat_s)[i];
		}
	}
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*stat_s;
	char		c;
	int			i;
	int			j;

	res = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	stat_s = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	i = 0;
	j = 0;
	while (read(fd, &c, 1) && i < BUFFER_SIZE)
	{
		if (c != '\n')
			res[i++] = c;
		else if (i < BUFFER_SIZE)
		{
			while (read(fd, &c, 1) && j < BUFFER_SIZE)
				stat_s[j++] = c;
			break ;
		}
	}
	return (res);
}
