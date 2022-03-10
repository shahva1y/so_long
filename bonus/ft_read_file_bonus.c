#include "so_long_bonus.h"

static t_bool	ft_line_isempty(char *line)
{
	if (!line)
		return (TRUE);
	if (line[0] == '\0')
		return (TRUE);
	return (FALSE);
}

static int	ft_skip_empty_lines(int fd, char **line)
{
	int	rd;

	rd = 1;
	while (0 < rd && ft_line_isempty(*line))
	{
		ft_free(*line);
		rd = ft_get_next_line(fd, line);
	}
	return (rd);
}

static t_list	*ft_collect_lines(int fd, char **line)
{
	int		rd;
	t_list	*list;

	list = NULL;
	rd = 1;
	while (0 < rd && !ft_line_isempty(*line))
	{
		list = ft_t_list_add(list, *line);
		if (!list)
			return (NULL);
		rd = ft_get_next_line(fd, line);
	}
	if (rd < 0)
	{
		ft_free_t_list_with_content(list);
		return (NULL);
	}
	return (list);
}

static t_list	*ft_t_list_from_fd(int fd)
{
	t_list	*list;
	char	*line;
	int		rd;

	line = NULL;
	rd = ft_skip_empty_lines(fd, &line);
	if (rd == 0)
		ft_error("empty file error!");
	if (rd < 1)
		return (NULL);
	list = ft_collect_lines(fd, &line);
	if (!list)
		return (NULL);
	rd = ft_skip_empty_lines(fd, &line);
	if (rd > 0)
	{
		ft_free(line);
		ft_error("double map error!");
	}
	if (rd != 0)
	{
		ft_free_t_list_with_content(list);
		return (NULL);
	}
	return (list);
}

char	**ft_read_file(int fd)
{
	t_list	*list;
	char	**array;

	list = ft_t_list_from_fd(fd);
	if (!list)
		return (NULL);
	if (!ft_check_walls(list))
	{
		ft_free_t_list(list);
		ft_error("Wall error!");
		return (NULL);
	}
	if (!ft_check_inside(list))
	{
		ft_free_t_list(list);
		return (NULL);
	}
	array = ft_t_list_to_array(list);
	ft_free_t_list(list);
	if (!array)
		return (NULL);
	return (array);
}
