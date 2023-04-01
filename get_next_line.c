/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:41:08 by ekuchel           #+#    #+#             */
/*   Updated: 2023/03/30 11:20:14 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_storage(int fd, char *strholder)
{
	char		*buff;
	int			nb_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (NULL);
	nb_read = 1;
	while (nb_read)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buff);
			free(strholder);
			return (NULL);
		}
		buff[nb_read] = '\0';
		if (!strholder)
			strholder = ft_strdup("");
		strholder = ft_strjoin(strholder, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (strholder);
}

char	*ft_substraction(char *strholder)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!strholder[i])
		return (NULL);
	while (strholder[i] != '\n' && strholder[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(*line) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (strholder[i] != '\n' && strholder[i])
	{
		line[i] = strholder[i];
		i++;
	}
	if (strholder[i] == '\n')
	{
		line[i] = strholder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_strholder(char *strholder)
{
	int		i;
	char	*newline;

	i = 0;
	while (strholder[i] != '\0' && strholder[i] != '\n')
		i++;
	if (!strholder[i])
	{
		free(strholder);
		return (NULL);
	}
	newline = malloc((ft_strlen(strholder) - i + 1) * sizeof(*newline));
	if (!newline)
		return (NULL);
	i++;
	newline = ft_strcpy(newline, &strholder[i]);
	free(strholder);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strholder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	strholder = ft_str_storage(fd, strholder);
	if (!strholder)
	{
		free(strholder);
		return (NULL);
	}
	line = ft_substraction(strholder);
	strholder = ft_new_strholder(strholder);
	return (line);
}
