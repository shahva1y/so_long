#include "so_long.h"

void	ft_error(char *error_messege)
{
	write(2, "Error\n", 6);
	//+ явное сообщение об ошибке
	write(2, error_messege, ft_strlen(error_messege));
	exit(1);
}

int	ft_check_file(char	*file)
{
	char	*format;
	int		fd;

	format = ft_strchr(file, '.');
	if (ft_strcmp(format, ".ber"))
		ft_error("Oooops! Only .ber file!");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Oooops! File doest open!");
	return (fd);
}

#include <stdio.h>
t_meta	*ft_process_args(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_meta	*game;

	if (argc != 2)
		ft_error("Usage: ./so_long file_name.ber");

	fd = ft_check_file(argv[1]);
	//->map??? - нам эта переменная пригодится для будущей работы
	map = ft_parse_file(fd);
	//сбор информации об игре и дополнительная валидация!
	game = ft_parse_map(map);
	//
	int	i = 0;
	while ((game->map)[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (game);
}