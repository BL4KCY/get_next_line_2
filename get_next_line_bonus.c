/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:12:45 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/19 11:47:27 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*next_buffer(char *buffer)
{
	char	*line;
	int		index;
	int		i;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(((ft_strlen(buffer) - index++) + 1), sizeof(char));
	i = 0;
	while (buffer[index])
		line[i++] = buffer[index++];
	free(buffer);
	return (line);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = ft_calloc(index + 2, sizeof(char));
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
		line[index] = '\n';
	return (line);
}

char	*read_to_endl(int fd, char *bfr)
{
	char	*buffer;
	int		b_readed;

	if (!bfr)
		bfr = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b_readed = 1;
	while (b_readed > 0 && !ft_strchr(buffer, '\n'))
	{
		b_readed = read(fd, buffer, BUFFER_SIZE);
		if (b_readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[b_readed] = 0;
		bfr = join_and_free(bfr, buffer);
	}
	free(buffer);
	return (bfr);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_to_endl(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = next_buffer(buffer[fd]);
	return (line);
}
