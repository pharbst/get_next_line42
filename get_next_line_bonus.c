/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:35 by pharbst           #+#    #+#             */
/*   Updated: 2022/06/25 22:01:47 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*ft_new_stash(char *stash)
{
	char	*new_stash;

	if (!ft_strchr(stash, '\n'))
		return (NULL);
	new_stash = ft_strdup(ft_strchr(stash, '\n') + 1);
	free(stash);
	return (new_stash);
}

char	*get_line(char *stash)
{
	char	*line;
	size_t	n;

	if (!stash)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
		return (line = ft_strdup(stash), free(stash), line);
	line = malloc(((ft_strchr(stash, '\n') - stash) + 2) * sizeof(char));
	if (!line)
		return (free(stash), NULL);
	n = 0;
	while (stash[n] != '\n')
	{
		line[n] = stash[n];
		n++;
	}
	line[n++] = '\n';
	line[n] = '\0';
	return (line);
}

char	*ft_stash(int fd, char *stash)
{
	char	*buff;
	int		n;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n = BUFFER_SIZE;
	while (n == BUFFER_SIZE && !ft_strchr(stash, '\n'))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			return (free(buff), NULL);
		if (n == 0)
			return (free(buff), stash);
		buff[n] = '\0';
		stash = ft_strjoinfree(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_stash(fd, stash[fd]);
	line = get_line(stash[fd]);
	stash[fd] = ft_new_stash(stash[fd]);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
