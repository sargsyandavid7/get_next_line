/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:42:14 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/05 17:09:04 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static long long	find_index(char *buffer)
{
	long long	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*temp;
	long long	size;
	long long	index;

	size = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buff)
		buff = (char *)malloc(BUFFER_SIZE + 1);
	size = read(fd, buff, BUFFER_SIZE);
	if (size == 0)
		return (NULL);
	buff[size] = '\0';
	index = find_index(buff);
	while (index == -1)
	{
		temp = (char *)malloc(BUFFER_SIZE + 1);
		size = read(fd, temp, BUFFER_SIZE);
		temp[size] = '\0';
		if (size == 0)
		{
			free(temp);
			return (buff);
		}
		buff = ft_strjoin(buff, temp);
		index = find_index(buff);
		free(temp);
	}
	temp = ft_substr(buff, 0, index + 1, 0);
	buff = ft_substr(buff, index + 1, ft_strlen(buff) - index, 1);
	return (temp);
}
