/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:49:46 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/12/04 02:54:40 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_str(char *s)
{
	int	i;
	int	is_true;

	i = 0;
	is_true = 1;
	if (!s)
		return (NULL);
	while (s[i] && is_true)
	{
		if (s[i] == '\n')
			is_true = 0;
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*return_after_newline(char *s)
{
	int		len;
	char	*ret;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	if (s[len] == '\0')
		return (NULL);
	ret = ft_strdup(s + len);
	return (ret);
}

static char	*freed(char *buff, char	*temp)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	return NULL;
}

static char *read_buff(int fd, char *buffer, char *line)
{
	int	bytes_read;
	char	*new_line = NULL;

	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		new_line = ft_strjoin(line, buffer);
		free(line);
		line = new_line;
	}
	return line;
}

char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*line = NULL;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || BUFFER_SIZE == 0)
		return (freed(buffer, temp));
	line = ft_strdup("");
	if (temp)
	{
		line = ft_strjoin(line, temp);
		free(temp);
		temp = NULL;
	}
	line = read_buff(fd, buffer, line);
	if (!line)
		return freed(buffer, temp);
	free(buffer);
	temp = return_after_newline(line);
	return (add_str(line));
}
