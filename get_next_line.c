/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:42:14 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/04 18:34:34 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long	find_indicator(long long i, char *buff)
{
	while (buff[i++])
	{
		if (buff[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*temp;
	long long	indicator;
	long long	size;

	if (!buff)
		buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff || fd < 0)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	buff[size] = '\0';
	indicator = 0;
	if (size < 0 || !buff)
	{
		free(buff);
		return (NULL);
	}
	indicator = find_indicator(0, buff);
	if (size < BUFFER_SIZE && indicator == -1)
		return (buff);
	while (indicator == -1)
	{
		temp = (char *)malloc(BUFFER_SIZE + 1);
		size = read(fd, temp, BUFFER_SIZE);
		temp[size] = '\0';
		buff = ft_strjoin(buff, temp);
		indicator = find_indicator(0, buff);
		free(temp);
	}
	printf("%s",buff);
	return (temp);
}
