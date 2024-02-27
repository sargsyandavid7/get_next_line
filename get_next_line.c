/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:18:51 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/27 11:26:06 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	static char	mini_buff[1];

	buff = ft_strdup("");
	if (fd == -1)
		return (NULL);
	while (read(fd, mini_buff, 1))
	{
		buff = ft_strjoin(buff, mini_buff);
		if (buff == NULL)
			return (NULL);
		if (mini_buff[0] == '\n')
		{
			write(1, buff, ft_strlen(buff));
			return (buff);
		}
	}
	return (buff);
}
