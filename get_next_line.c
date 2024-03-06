/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:42:14 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/06 18:37:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long	find_line(char *return_char)
{
	long long	i;

	while (return_char[i])
	{
		if (return_char[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_stay_char(int fd)
{
	
}

char	*get_return_char(int fd, char *stay_char)
{
	long long	size;
	char		*return_char;
	char		*temp;
	long long	line;

	return_char = malloc(BUFFER_SIZE + 1);
	
	size = read(fd, return_char, BUFFER_SIZE);
	if (size == 0)
	{
		free(return_char);
		line = find_line(stay_char);
		if (line == -1)
			return (stay_char);
		stay_char = ft_substr(stay_char, line, ft_strlen(stay_char) - line,1);
		return (stay_char);
	}
	return_char[size] = '\0';
	if (ft_strlen(return_char) < BUFFER_SIZE)
		return_char = ft_substr(return_char, 0, size, 1);
	line = find_line(return_char);
	while (line == -1)
	{
		temp = malloc(BUFFER_SIZE + 1);
		size = read(fd, temp, BUFFER_SIZE);
		temp[size] = '\0';
		if (size == 0)
		{
			free(temp);
			if (ft_strlen(stay_char) != 0)
				return (ft_strjoin(stay_char, return_char));
			else 
				return (return_char);
		}
		return_char = ft_strjoin(return_char, temp);
		line = find_line(return_char);
		free(temp);
	}
	temp = ft_substr(return_char, 0, line + 1, 1);
	stay_char = ft_substr(return_char, line + 1, ft_strlen(return_char) - line, 0);
}

char	*get_next_line(int fd)
{
	static char	*stay_char;
	char		*return_char;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		if (stay_char)
			free(stay_char);
		stay_char = NULL;
		return (NULL);
	}
	
}