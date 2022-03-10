#include "so_long.h"

static t_bool	ft_error_t_img(t_img *img)
{
	if (!(img->items) || !(img->exit) || !(img->space)
		|| !(img->wall) || !(img->hero_dir[1])
		|| !(img->hero_dir[0]) || !(img->hero_dir[2]))
		return (FALSE);
	return (TRUE);
}

static void	ft_define_t_img(t_mlx *mlx, t_img *img)
{
	int		scale;

	img->tick = 0;
	img->items = ft_init_t_cell_items(mlx->mlx);
	img->exit = mlx_xpm_file_to_image(mlx->mlx, IMG_EXIT, &scale, &scale);
	img->space = mlx_xpm_file_to_image(mlx->mlx, IMG_SPACE, &scale, &scale);
	img->wall = mlx_xpm_file_to_image(mlx->mlx, IMG_WALL, &scale, &scale);
	img->enemy = ft_init_t_cell_enemy(mlx->mlx);
	img->hero_dir[0] = ft_init_t_cell_hero_right(mlx->mlx);
	img->hero_dir[1] = ft_init_t_cell_hero_left(mlx->mlx);
	img->hero_dir[2] = ft_init_t_cell_hero_up(mlx->mlx);
	img->hero = img->hero_dir[0];
}

t_img	*ft_init_t_img(t_mlx *mlx)
{
	t_img	*img;

	if (!mlx)
		return (NULL);
	img = malloc(sizeof(t_img));
	if (!img)
	{
		ft_error("memory allocation error! (t_img)");
		return (NULL);
	}
	ft_define_t_img(mlx, img);
	if (!ft_error_t_img(img))
	{
		ft_error("xpm_file_to_image error!");
		ft_destroy_t_img(mlx, img);
		return (NULL);
	}
	return (img);
}

void	ft_destroy_t_img(t_mlx *mlx, t_img *img)
{
	if (mlx && img)
	{
		if (img->wall)
			mlx_destroy_image(mlx->mlx, img->wall);
		if (img->space)
			mlx_destroy_image(mlx->mlx, img->space);
		if (img->exit)
			mlx_destroy_image(mlx->mlx, img->exit);
		if (img->items)
			ft_destroy_t_cell(mlx, img->items);
		if ((img->hero_dir)[0])
			ft_destroy_t_cell(mlx, (img->hero_dir)[0]);
		if ((img->hero_dir)[1])
			ft_destroy_t_cell(mlx, (img->hero_dir)[1]);
		if ((img->hero_dir)[2])
			ft_destroy_t_cell(mlx, (img->hero_dir)[2]);
		if (img->enemy)
			ft_destroy_t_cell(mlx, img->enemy);
		ft_free(img);
	}
}
