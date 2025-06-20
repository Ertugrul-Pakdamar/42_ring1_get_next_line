/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:41 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/20 14:16:44 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check_buffer(char **res, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(*res);
	while ((*buffer)[i] != '\n' && i < BUFFER_SIZE)
	{
		(*res)[j + i] = (*buffer)[i];
		i++;
	}
	(*res)[j + i] = '\0';
	if ((*buffer)[i] == '\n')
	{
		(*buffer) = &((*buffer)[i + 1]);
		return (1);
	}
	if (i == BUFFER_SIZE)
		return (0);
	return (2);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*buffer;
	int			i;
	int			check;

	res = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (check_buffer(&res, &buffer))
		return (res);
	i = 0;
	check = read(fd, buffer, BUFFER_SIZE);
	while (check != -1 && check != 0)
	{
		if (check_buffer(&res, &buffer))
			return (res);
		i++;
		res = (char *)ft_realloc(res, BUFFER_SIZE * i, BUFFER_SIZE * (i + 1));
		check = read(fd, buffer, BUFFER_SIZE);
	}
	if (check == 0)
		return (res);
	return (NULL);
}
