#include "so_long.h"

t_mlx	*ft_init_t_mlx(t_meta *meta)
{
	t_mlx	*mlx;
	int		height;
	int		width;

	if (!meta)
		return (NULL);
	height = (meta->map)->height;
	width = (meta->map)->width;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		ft_error("memory allocation error! (t_mlx)");
		return (NULL);
	}
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx,
			width * IMG_WIDTH, (height + 1) * IMG_HEIGHT, "So_long");
	if (!(mlx->mlx) || !(mlx->win))
	{
		ft_error("mlx or win init error!");
		ft_destroy_t_mlx(mlx);
		return (NULL);
	}
	return (mlx);
}

void	ft_destroy_t_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		ft_free(mlx->mlx);
		free(mlx);
	}
}
