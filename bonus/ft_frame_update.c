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
			(img->items)->img, x * IMG_WIDTH, y * IMG_HEIGHT);
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
			(img->hero)->img, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (symbol == 'X')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			(img->enemy)->img, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	ft_t_img_update(t_img	*img)
{
	if (img->tick % 5 == 0)
	{
		img->hero = (img->hero)->next;
		img->items = (img->items)->next;
		img->enemy = (img->enemy)->next;
	}
	img->tick += 1;
}

static void	ft_frame_render(t_set *set)
{
	int		x;
	int		y;
	t_map	*map;
	char	*steps;

	map = ((set->meta)->map);
	ft_t_img_update(set->img);
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
	steps = ft_itoa(((set->meta)->hero)->steps);
	mlx_string_put((set->mlx)->mlx, (set->mlx)->win,
		x * IMG_WIDTH / 2, (y + 0.55) * IMG_HEIGHT, -1, steps);
	ft_free(steps);
}

int	ft_frame_update(t_set *set)
{
	mlx_clear_window((set->mlx)->mlx, (set->mlx)->win);
	if (set->img->tick == 20)
	{
		if (!ft_move_t_enemy((set->meta)->enemy, (set->meta)->map))
			ft_exit(set);
		set->img->tick = 0;
	}
	ft_frame_render(set);
	return (0);
}
