/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:52:40 by tatashir          #+#    #+#             */
/*   Updated: 2023/01/21 18:31:15 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i += 1;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free (save);
	return (s);
}

char	*ft_read(int fd, char *save)
{
	char	*buf;
	int		read_byte;
	char	*tmp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(save, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
	}
	free (buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
