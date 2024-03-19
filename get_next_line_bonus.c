/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:24:29 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/19 13:03:24 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

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

char	*get_readed(int fd, char **st_char)
{
	char		*readed;
	char		*temp;
	long long	size;

	readed = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	size = read(fd, readed, BUFFER_SIZE);
	if (size < 0)
	{
		free(st_char[fd]);
		st_char[fd] = NULL;
	}
	if (size <= 0 || !readed)
	{
		free(readed);
		return (NULL);
	}
	while (find_newline(readed) == -1 && size != 0)
	{
		temp = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		size = read(fd, temp, BUFFER_SIZE);
		readed = ft_strjoin(readed, temp, 1, 1);
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*st_char[OPEN_MAX];
	char		*line;
	char		*readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	readed = get_readed(fd, st_char);
	line = get_return_line(st_char[fd], readed);
	st_char[fd] = get_st_char(readed, st_char[fd]);
	return (line);
}

/*int main()
 {
 	//int fd4 = open("a.txt",O_RDONLY);
 	//printf("%s\n",get_next_line(1040));
 	printf("%s\n",get_next_line(10367));
 	printf("%s\n",get_next_line(10));
 	printf("%s\n",get_next_line(10));
	printf("%s\n", get_next_line(2));
 	//printf("%s\n",get_next_line(10241));
 	//printf("%s\n",get_next_line(10242));
 	//printf("%s\n",get_next_line(10243));
 	////system("leaks a.out");
 	//printf("%s",get_next_line(fd2));
 	//printf("%s",get_next_line(fd1));
 	////system("leaks a.out");
 	//printf("%s",get_next_line(fd4));
 	// get_next_line(fd1);
 	// get_next_line(11);
 	// get_next_line(33);
 	// get_next_line(-2);
 	//system("leaks a.out");
 	//get_next_line(fd4);
 	//system("leaks a.out");
 }
*/
/*
int	main(void)
{
	int	i;
	int	fd;
	int 	fd2 = 2;
	char	*ch1;
	char	*ch2;

	i = 10;
	fd = open("a.txt", O_RDONLY);
	// fd2 = open("gnl2.txt", O_RDONLY);
//printf("%s\n", get_next_line(fd));	
//printf("%s\n", get_next_line(fd2));
//printf("%s\n", get_next_line(fd));
//printf("%s\n", get_next_line(fd2));
	 while (i--)
	 {
		 ch1 = get_next_line(fd);
		 ch2 = get_next_line(fd2);
		 printf("[%s]\n", ch1);
		 printf("❌ [%s]\n", ch2);
		 free(ch1);
	 }
	close(fd);
}*/