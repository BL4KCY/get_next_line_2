/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:01:18 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/18 07:49:44 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *str, int c);

void	*ft_calloc(size_t elementCount, size_t elementSize);

size_t	ft_strlen(const char *s);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif