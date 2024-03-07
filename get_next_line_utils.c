/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:58:35 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/07 20:13:38 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_substr(char *s, unsigned int start, size_t len, int f)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s || len == 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		a = (char *)malloc(1 * sizeof(char));
		a[0] = '\0';
		return (a);
	}
	if (len > ft_strlen(s) - start)
		a = (char *)malloc(ft_strlen(s) - start + 1);
	else
		a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[i + start])
	{
		a[i] = s[i + start];
		i++;
	}
	a[i] = '\0';
	if (f)
		free(s);
	return (a);
}

char	*ft_strjoin(char *s1, char *s2, int f, int f2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	if (f)
		free(s1);
	if (f2)
		free(s2);
	joined[i + j] = '\0';
	return (joined);
}
