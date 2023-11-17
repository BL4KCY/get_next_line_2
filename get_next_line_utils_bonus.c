/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:01:00 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/17 23:20:48 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		sizetotal;
	int		index;
	int		i;

	index = (-1);
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	buffer = malloc(sizeof(char) * (sizetotal + 1));
	if (!buffer)
		return (NULL);
	while (s1[++index])
		buffer[index] = s1[index];
	i = (-1);
	while (s2[++i])
		buffer[index++] = s2[i];
	buffer[sizetotal] = 0;
	return (buffer);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;
	size_t	index;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	index = 0;
	while (index < elementCount * elementSize)
		res[index++] = 0;
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
