#include "so_long.h"

static t_bool	ft_error_t_img(t_img *img)
{
	if (!(img->items) || !(img->exit) || !(img->space)
		|| !(img->wall) || !(img->hero) || !(img->hero_dir)[0]
		|| !(img->hero_dir)[1] || !(img->hero_dir)[2])
		return (FALSE);
	return (TRUE);
}

static void	ft_define_t_img(t_mlx *mlx, t_img *img)
{
	int		scale;

	img->items = mlx_xpm_file_to_image(mlx->mlx, IMG_ITEM, &scale, &scale);
	img->exit = mlx_xpm_file_to_image(mlx->mlx, IMG_EXIT, &scale, &scale);
	img->space = mlx_xpm_file_to_image(mlx->mlx, IMG_SPACE, &scale, &scale);
	img->wall = mlx_xpm_file_to_image(mlx->mlx, IMG_WALL, &scale, &scale);
	(img->hero_dir)[0] = mlx_xpm_file_to_image(mlx->mlx, IMG_HERO_RIGHT,
			&scale, &scale);
	(img->hero_dir)[1] = mlx_xpm_file_to_image(mlx->mlx, IMG_HERO_LEFT,
			&scale, &scale);
	(img->hero_dir)[2] = mlx_xpm_file_to_image(mlx->mlx, IMG_HERO_UP,
			&scale, &scale);
	img->hero = (img->hero_dir)[0];
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
		if ((img->hero_dir)[0])
			mlx_destroy_image(mlx->mlx, (img->hero_dir)[0]);
		if ((img->hero_dir)[1])
			mlx_destroy_image(mlx->mlx, (img->hero_dir)[1]);
		if ((img->hero_dir)[2])
			mlx_destroy_image(mlx->mlx, (img->hero_dir)[2]);
		if (img->wall)
			mlx_destroy_image(mlx->mlx, img->wall);
		if (img->space)
			mlx_destroy_image(mlx->mlx, img->space);
		if (img->items)
			mlx_destroy_image(mlx->mlx, img->items);
		if (img->exit)
			mlx_destroy_image(mlx->mlx, img->exit);
		ft_free(img);
	}
}
