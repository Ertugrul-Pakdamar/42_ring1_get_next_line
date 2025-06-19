/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:45 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/19 22:16:16 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	int		i;

	res = (void *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((char *)res)[i++] = 0;
	return (res);
}

// This function can not take NULL pointer
void	*ft_realloc(void *arr, size_t len, size_t size)
{
	char	*res;
	int		i;

	res = (char *)ft_calloc(size, sizeof(char));
	i = 0;
	while (i < len)
	{
		res[i] = ((char *)arr)[i];
		i++;
	}
	free(arr);
	return (res);
}
