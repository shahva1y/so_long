#include "so_long.h"

static t_bool	ft_error_t_img(t_img *img)
{
	if (!(img->items) || !(img->exit) || !(img->space)
		|| !(img->wall) || !(img->hero))
		return (FALSE);
	return (TRUE);
}

t_img	*ft_init_t_img(t_mlx *mlx)
{
	t_img	*img;
	int		width;
	int		height;

	if (!mlx)
		return (NULL);
	img = NULL;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		ft_error("OOOOOOpppps! img Error!");
		return (NULL);
	}
	img->items = mlx_xpm_file_to_image(mlx->mlx, IMG_ITEM, &width, &height);
	img->exit = mlx_xpm_file_to_image(mlx->mlx, IMG_EXIT, &width, &height);
	img->space = mlx_xpm_file_to_image(mlx->mlx, IMG_SPACE, &width, &height);
	img->wall = mlx_xpm_file_to_image(mlx->mlx, IMG_WALL, &width, &height);
	img->hero = mlx_xpm_file_to_image(mlx->mlx, IMG_HERO, &width, &height);
	if (!ft_error_t_img(img))
	{
		ft_free_t_img(img);
		ft_error("OOOOOOpppps! img Error!");
		return (NULL);
	}
	return (img);
}

void	ft_free_t_img(t_img *img)
{
	if (img)
	{
		ft_free(img->wall);
		ft_free(img->space);
		ft_free(img->items);
		ft_free(img->exit);
		ft_free(img->hero);
		free(img);
	}
}
