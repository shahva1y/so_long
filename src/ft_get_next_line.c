#include "so_long.h"

static int	ft_increase_memmory_size(char **line, int size)
{
	char	*newline;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(*line);
	newline = (char *) malloc((length + size) * sizeof(char));
	if (!newline)
	{
		ft_error("Ошибка выделения памяти!");
		return (-1);
	}
	newline[length + size - 1] = '\0';
	while ((*line)[i])
	{
		newline[i] = (*line)[i];
		i++;
	}
	newline[i] = '\0';
	free((*line));
	(*line) = newline;
	return (length + size);
}

static int	ft_read_line(int fd, char **buffer, int size)
{
	int		rd;
	int		i;
	char	c;

	rd = 1;
	i = 0;
	c = '\0';
	while (rd == 1 && c != '\n')
	{
		rd = (int) read(fd, &c, 1);
		if (rd < 0)
		{
			ft_error("read func error! return < 0");
			return (-1);
		}
		(*buffer)[i] = '\0' + rd * (c * (c != '\n') + '\0' * (c == '\n'));
		if (i + 2 == size)
			size = ft_increase_memmory_size(buffer, size);
		if (size < 0)
			return (-1);
		i += rd;
	}
	return (i);
}

int	ft_get_next_line(int fd, char **buffer)
{
	int		i;
	int		size;

	size = 1000;
	(*buffer) = malloc(size * sizeof(char));
	if (!(*buffer))
	{
		ft_error("memmory allocation error!");
		return (-1);
	}
	i = ft_read_line(fd, buffer, size);
	if (i < 1)
	{
		ft_free(*buffer);
		(*buffer) = NULL;
		return (i);
	}
	return (i);
}
