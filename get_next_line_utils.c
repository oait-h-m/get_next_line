/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:17:48 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/12/04 03:17:50 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_next_check_temp(char **line, char **temp, int fd)
{
	char	*newline;

	newline = ft_strjoin(*line, *temp);
	free(temp[fd]);
	free(*line);
	*line = NULL;
	temp[fd] = NULL;
	return (newline);
}


char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	a;

	i = 0;
	a = (char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	if (a == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		result[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[i + j] = s2[i];
		i++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
