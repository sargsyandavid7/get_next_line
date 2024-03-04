/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:42:14 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/04 22:01:18 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


long long	index_nl(char *line)
{
	long long	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*temp;
	long long		size;
	long long		index;

	if (!line)
		line = (char *)malloc(BUFFER_SIZE + 1);
	size = read(fd, line + ft_strlen(line), BUFFER_SIZE - ft_strlen(line));
	if (size < 0 || !line)
	{
		free(line);
		return (NULL);
	}
	index = index_nl(line);
	while (index == -1)
	{
		temp = (char *)malloc(BUFFER_SIZE + 1);
		size = read(fd, temp, BUFFER_SIZE);
		temp[size] = '\0';
		if (size == 0)
			return (line);
		line = ft_strjoin(line, temp);
		index = index_nl(line);
		free(temp);
	}
	temp = ft_substr(line, 0, index + 1);
	line = ft_substr(line, index + 1, ft_strlen(line) - index);
	printf("%s",temp);
	return (temp);
}
