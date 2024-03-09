/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:24:29 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/09 16:27:17 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

long long	find_newline(char *readed)
{
	long long	i;

	i = 0;
	if (!readed)
		return (-1);
	while (readed[i])
	{
		if (readed[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_st_char(char *readed, char *s)
{
	char		*st_char;

	if (readed == NULL)
	{
		if (find_newline(s) == -1 || !s)
		{
			free(s);
			return (NULL);
		}
		st_char = ft_substr(s, find_newline(s) + 1,
				ft_strlen(s) - find_newline(s), 1);
		return (st_char);
	}
	if (s != NULL)
		st_char = ft_strjoin(s, readed, 1, 1);
	else
		st_char = ft_substr(readed, 0, ft_strlen(readed), 1);
	if (find_newline(st_char) == -1 || !st_char)
	{
		free(st_char);
		return (NULL);
	}
	st_char = ft_substr(st_char, find_newline(st_char) + 1,
			ft_strlen(st_char) - find_newline(st_char), 1);
	return (st_char);
}

char	*get_return_line(char *st_char, char *readed)
{
	char		*line;
	long long	index;

	if (readed == NULL && st_char == NULL)
		return (NULL);
	else if (readed == NULL && st_char != NULL)
	{
		index = find_newline(st_char);
		if (index == -1)
			line = ft_substr(st_char, 0, ft_strlen(st_char), 0);
		else
			line = ft_substr(st_char, 0, index + 1, 0);
		return (line);
	}
	if (st_char != NULL)
		line = ft_strjoin(st_char, readed, 0, 0);
	else
		line = ft_substr(readed, 0, ft_strlen(readed), 0);
	index = find_newline(line);
	if (index == -1 || !line)
		index = ft_strlen(line) - 1;
	line = ft_substr(line, 0, index + 1, 1);
	return (line);
}

char	*get_readed(int fd)
{
	char		*readed;
	char		*temp;
	long long	nl;
	long long	size;

	readed = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	size = read(fd, readed, BUFFER_SIZE);
	if (size <= 0 || !readed)
	{
		free(readed);
		return (NULL);
	}
	if (size < BUFFER_SIZE)
		readed = ft_substr(readed, 0, size, 1);
	nl = find_newline(readed);
	while (nl == -1 && size != 0)
	{
		temp = (char *)calloc(1, BUFFER_SIZE + 1);
		size = read(fd, temp, BUFFER_SIZE);
		readed = ft_strjoin(readed, temp, 1, 1);
		nl = find_newline(readed);
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*st_char[OPEN_MAX];
	char		*line;
	char		*readed;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		free(st_char[fd]);
		st_char[fd] = NULL;
		return (NULL);
	}
	readed = get_readed(fd);
	line = get_return_line(st_char[fd], readed);
	st_char[fd] = get_st_char(readed, st_char[fd]);
	return (line);
}
