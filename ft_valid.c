#include "so_long.h"

void	ft_error(char *error_messege)
{
	write(2, "Error\n", 6);
	//+ явное сообщение об ошибке
	write(2, error_messege, ft_strlen(error_messege));
	exit(1);
}

t_bool	ft_check_file(char	*file)
{
	char *format;

	format = ft_strchr(file, '.');
	if (ft_strcmp(format, ".ber"))
		return (FALSE);
	return (TRUE);
}

void	ft_valid(t_mlx *mlx, int argc, char **argv)
{
	int	fd;

	(void)mlx;
	if (argc != 2)
		ft_error("Oooops! Only .ber file! on arguments");
	if (!ft_check_file(argv[1]))
		ft_error("Oooops! Only .ber file!");

	fd = open(argv[1], O_RDONLY);
	//нужно так же проверить разрешение .ber! В конце agrv[1] должно быть .ber!
	if (fd < 0)
		ft_error("Oooops! File doest open!");
}