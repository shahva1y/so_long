#include "so_long.h"

static void	ft_put_img_to_window(int x, int y, t_set *set)
{
	t_mlx	*mlx;
	t_img	*img;
	char	symbol;

	mlx = (set->mlx);
	img = (set)->img;
	symbol = (((set->meta)->map)->map)[y][x];
	if (symbol == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			img->items, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (symbol == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			img->space, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (symbol == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			img->wall, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (symbol == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			img->exit, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (symbol == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			img->hero, x * IMG_WIDTH, y * IMG_HEIGHT);
}

static void	ft_frame_render(t_set *set)
{
	int		x;
	int		y;
	t_map	*map;

	map = ((set->meta)->map);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			ft_put_img_to_window(x, y, set);
			y++;
		}
		x++;
	}
}

int	ft_frame_update(t_set *set)
{
	mlx_clear_window((set->mlx)->mlx, (set->mlx)->win);
	ft_frame_render(set);
	return (0);
}
