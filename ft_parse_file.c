#include "so_long.h"
#include <stdio.h>

static int	ft_memmory_boost(char **line, int size)
{
	char	*newline;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(*line);
	newline = (char *) malloc((length + size) * sizeof(char));
	if (!newline)
		ft_error("Ошибка выделения памяти!");
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

static int	ft_read_line(int fd, char **buffer)
{
	int		i;
	char	c;
	int		size;

	i = 0;
	c = '\0';
	size = 1000;
	(*buffer) = malloc(size * sizeof(char));
	if (!(*buffer))
		ft_error("Oooops! Memory allocation error!");
	while (read(fd, &c, 1) && c != '\n' && c != '\0')
	{
		(*buffer)[i] = c;
		if (i + 2 == size)
			size = ft_memmory_boost(buffer, size);
		i++;
	}
	(*buffer)[i] = '\0';
	if (i == 0 && c == '\0')
	{
		free((*buffer));
		(*buffer) = NULL;
	}
	if (i == 0 && c == '\n')
		i++;
	return (i);
}

static t_bool	ft_isvalid_char(char c)
{
	//'\n'
	if (c != '1' && c != '0'
		&& c != 'P' && c != 'C' && c != 'E')
		return (FALSE);
	return (TRUE);
}


static t_bool	ft_iswall(char	*line)
{
	int	i;

	i = 0;
	while(line[i] == '1')
		i++;
	if (line[i] == '\0' && i != 0)
		return (TRUE);
	return (FALSE);
}


static t_bool	ft_check_line(char *line)
{
	int	i;

	if (!line)
		return (FALSE);
	if (line[0] == '\0')
		return (FALSE);
	i = 0;
	while (line[i])
	{
		if (!ft_isvalid_char(line[i]))
			ft_error("Ooooops!");
		i++;
	}
	return (TRUE);
}


char	**ft_parse_file(int fd)
{
	char	*line;
	t_node	*list;
	char	**map;

	line = NULL;
	list = 0;
	//условие в цикле можно заменить на более общую функцию!
	//ft_get_map();
	//ft_isvalid_map();
	//Создание карты из файла в виде списка.
	while (ft_read_line(fd, &line) && !ft_check_line(line))
		free(line);
	ft_list_add(&list, line);
	while (ft_read_line(fd, &line) && ft_check_line(line))
		ft_list_add(&list, line);
	while (ft_read_line(fd, &line) && !ft_check_line(line))
		free(line);
	if (line)
		ft_error("Ooooops!");

	//list != NULL?????
	//??? ft_check_perimeter????
	t_node	*tmp;
	unsigned int		width;

	//варлидация карты
	tmp = list;
	//+проверка длинны
	width = ft_strlen(tmp->line);
	if (!ft_iswall(tmp->line))
		ft_error("Wall error!");
	while(tmp->next != NULL)
	{
		//+проверка на 1 в начале и в конце
		//+проверка на наличие необходимых элементов карты
		if (width != ft_strlen(tmp->line))
			ft_error("Wall error!");
		if ((tmp->line)[0] != '1' || (tmp->line)[width - 1] != '1')
			ft_error("Wall error!");
		tmp = tmp->next;
	}
	if (!ft_iswall(tmp->line) || width != ft_strlen(tmp->line))
		ft_error("Wall error!");
	//Карта в виде массива
	map = ft_list_to_array(list);
	ft_list_free(list);
	return (map);
}