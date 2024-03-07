/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:42:14 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/07 22:50:35 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long	find_newline(char *readed)
{
	long long	i;

	i = 0;
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
	long long	index;

	if (readed == NULL)
	{
		if (s == NULL)
			return (NULL);
		index = find_newline(s);
		if (index == -1)
		{
			free(s);
			return (NULL);
		}
		st_char = ft_substr(s, index + 1, ft_strlen(s) - index, 1);
		return (st_char);
	}
	index = find_newline(readed);
	if (index == -1)
	{
		free(s);
		free(readed);
		return (NULL);
	}
	st_char = ft_substr(readed, index + 1, ft_strlen(readed) - index, 1);
	free(s);
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
		readed = ft_strjoin(st_char, readed, 0, 1);
	index = find_newline(readed);
	if (index == -1)
		index = ft_strlen(readed);
	line = ft_substr(readed, 0, index + 1, 0);
	return (line);
}

char	*get_readed(int fd)
{
	char		*readed;
	char		*temp;
	long long	nl;
	long long	size;

	readed = (char *)calloc(1, BUFFER_SIZE + 1);
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
	static char	*st_char;
	char		*line;
	char		*readed;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		st_char = NULL;
		return (NULL);
	}
	readed = get_readed(fd);
	//printf("---------------------------readed is %s|",readed);
	line = get_return_line(st_char, readed);
	//printf("----------------------------line is %s|",line);
	st_char = get_st_char(readed, st_char);
	//printf("----------------------------st_char is %s|",st_char);
	return (line);
}
