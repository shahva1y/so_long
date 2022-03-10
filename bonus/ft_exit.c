#include "so_long.h"

int	ft_exit(t_set	*set)
{
	ft_free_t_set(set);
	exit(0);
}

void	ft_error_exit(t_meta *meta, t_mlx *mlx, t_img *img)
{
	ft_free_t_meta(meta);
	ft_destroy_t_img(mlx, img);
	ft_destroy_t_mlx(mlx);
	exit(1);
}

void	ft_error(char *error_messege)
{
	write(2, "Error\n", 6);
	write(2, error_messege, ft_strlen(error_messege));
}
