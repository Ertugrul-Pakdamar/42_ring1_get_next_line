/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:45 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/19 20:28:10 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
