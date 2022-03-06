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
		ft_error("t_mlx init error!");
		return (NULL);
	}
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx,
			width * IMG_WIDTH, height * IMG_HEIGHT, "So_long");
	if (!(mlx->mlx) || !(mlx->win))
	{
		ft_error("mlx or win init error!");
		ft_free_t_mlx(mlx);
		return (NULL);
	}
	return (mlx);
}

void	ft_free_t_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		ft_free(mlx->mlx);
		ft_free(mlx->win);
		free(mlx);
	}
}
