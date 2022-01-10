/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/09 19:14:04 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/09 19:14:05 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

static char	*go_next_line(char *file)
{
	char	*temp;

	if ((unsigned int)stop_newline(file) < ft_strlen_next(file))
	{
		temp = ft_substr_next(file, stop_newline(file)
				+ 1, ft_strlen_next(file));
		free(file);
		file = temp;
	}
	else
		file = NULL;
	return (file);
}

char	*get_line(char *file)
{
	char	*line;

	if ((unsigned int)stop_newline(file) < ft_strlen_next(file))
		line = ft_substr_next(file, 0, stop_newline(file) + 1);
	else
		line = file;
	return (line);
}

static char	*get_thisbuff(char *buff, char *file)
{
	char	*temp;

	if (file)
	{
		temp = ft_strjoin_next(file, buff);
		free(file);
		file = temp;
	}
	else
		file = ft_strdup_next(buff);
	return (file);
}

static char	*get_file_next(char *file, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		if (file)
			if (stop_newline(file) != -1)
				break ;
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		file = get_thisbuff(buff, file);
		if (file == NULL)
			return (NULL);
	}
	if (ret == 0 && ft_strlen_next(file) == 0)
	{
		free(file);
		return (NULL);
	}
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file[OPEN_MAX];
	char		*line;

	line = NULL;
	if ((fd < 0 && fd <= OPEN_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	file[fd] = get_file_next(file[fd], fd);
	if (file[fd])
	{
		line = get_line(file[fd]);
		file[fd] = go_next_line(file[fd]);
	}
	return (line);
}
