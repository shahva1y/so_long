#include "so_long_bonus.h"

static t_bool	ft_check_format(char *file)
{
	char	*format;

	format = ft_strchr(file, '.');
	if (ft_strcmp(format, ".ber"))
		return (FALSE);
	return (TRUE);
}

int	ft_open_file(char	*file)
{
	int		fd;

	if (!ft_check_format(file))
	{
		ft_error("file format error! (only .ber file)");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("open file error!");
	return (fd);
}

t_meta	*ft_parse_file(char *file)
{
	int		fd;
	char	**array;
	t_meta	*meta;

	fd = ft_open_file(file);
	if (fd < 0)
		return (NULL);
	array = ft_read_file(fd);
	if (close(fd) == -1)
	{
		ft_free_array(array);
		ft_error("file close error!");
		return (NULL);
	}
	if (!array)
		return (NULL);
	meta = ft_parse_map(array);
	if (!meta)
	{
		ft_free_array(array);
		return (NULL);
	}
	return (meta);
}
