#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

static char	*go_next_line(char *file)
{
	char	*temp;

	if ((unsigned int)stop_newline(file) < ft_strlen(file))
	{
		temp = ft_substr(file, stop_newline(file) + 1, ft_strlen(file));
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

	if ((unsigned int)stop_newline(file) < ft_strlen(file))
		line = ft_substr(file, 0, stop_newline(file) + 1);
	else
		line = file;
	return (line);
}

static char	*get_thisbuff(char *buff, char *file)
{
	char	*temp;

	if (file)
	{
		temp = ft_strjoin(file, buff);
		free(file);
		file = temp;
	}
	else
		file = ft_strdup(buff);
	return (file);
}

static char	*get_file(char *file, int fd)
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
	if (ret == 0 && ft_strlen(file) == 0)
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
	file[fd] = get_file(file[fd], fd);
	if (file[fd])
	{
		line = get_line(file[fd]);
		file[fd] = go_next_line(file[fd]);
	}
	return (line);
}
