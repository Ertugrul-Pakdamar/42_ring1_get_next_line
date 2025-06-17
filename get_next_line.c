/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:41 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/17 22:02:01 by epakdama         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	int		i;
	char	c;
	char	*s;

	i = 0;
	while ((i = read(fd, &c, 1)) != '\0')
	{
		if (c == '\n')
			break ;
	}
	s = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (read(fd, &c, 1) != '\0')
	{
		s[i++] = c;
		if (c == '\n')
			break ;
	}
	return (s);
}
