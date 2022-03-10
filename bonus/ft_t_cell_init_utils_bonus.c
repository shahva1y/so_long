#include "so_long_bonus.h"

t_cell	*ft_init_t_cell_hero_up(void *mlx)
{
	t_cell	*cell;
	int		scale;
	void	*img0;
	void	*img1;
	void	*img2;

	cell = NULL;
	img0 = mlx_xpm_file_to_image(mlx, IMG_HERO_UP0, &scale, &scale);
	img1 = mlx_xpm_file_to_image(mlx, IMG_HERO_UP1, &scale, &scale);
	img2 = mlx_xpm_file_to_image(mlx, IMG_HERO_UP2, &scale, &scale);
	if (!img0 || !img1 || !img2)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img0);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img1);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img2);
	if (!cell)
		return (NULL);
	return (cell);
}

t_cell	*ft_init_t_cell_hero_right(void *mlx)
{
	t_cell	*cell;
	int		scale;
	void	*img0;
	void	*img1;
	void	*img2;

	cell = NULL;
	img0 = mlx_xpm_file_to_image(mlx, IMG_HERO_RIGHT0, &scale, &scale);
	img1 = mlx_xpm_file_to_image(mlx, IMG_HERO_RIGHT1, &scale, &scale);
	img2 = mlx_xpm_file_to_image(mlx, IMG_HERO_RIGHT2, &scale, &scale);
	if (!img0 || !img1 || !img2)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img0);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img1);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img2);
	if (!cell)
		return (NULL);
	return (cell);
}

t_cell	*ft_init_t_cell_hero_left(void *mlx)
{
	t_cell	*cell;
	int		scale;
	void	*img0;
	void	*img1;
	void	*img2;

	cell = NULL;
	img0 = mlx_xpm_file_to_image(mlx, IMG_HERO_LEFT0, &scale, &scale);
	img1 = mlx_xpm_file_to_image(mlx, IMG_HERO_LEFT1, &scale, &scale);
	img2 = mlx_xpm_file_to_image(mlx, IMG_HERO_LEFT2, &scale, &scale);
	if (!img0 || !img1 || !img2)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img0);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img1);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img2);
	if (!cell)
		return (NULL);
	return (cell);
}

t_cell	*ft_init_t_cell_items(void *mlx)
{
	t_cell	*cell;
	int		scale;
	void	*img0;
	void	*img1;
	void	*img2;

	cell = NULL;
	img0 = mlx_xpm_file_to_image(mlx, IMG_ITEM0, &scale, &scale);
	img1 = mlx_xpm_file_to_image(mlx, IMG_ITEM1, &scale, &scale);
	img2 = mlx_xpm_file_to_image(mlx, IMG_ITEM2, &scale, &scale);
	if (!img0 || !img1 || !img2)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img0);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img1);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img2);
	if (!cell)
		return (NULL);
	return (cell);
}

t_cell	*ft_init_t_cell_enemy(void *mlx)
{
	t_cell	*cell;
	int		scale;
	void	*img0;
	void	*img1;
	void	*img2;

	cell = NULL;
	img0 = mlx_xpm_file_to_image(mlx, IMG_ENEMY0, &scale, &scale);
	img1 = mlx_xpm_file_to_image(mlx, IMG_ENEMY1, &scale, &scale);
	img2 = mlx_xpm_file_to_image(mlx, IMG_ENEMY2, &scale, &scale);
	if (!img0 || !img1 || !img2)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img0);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img1);
	if (!cell)
		return (NULL);
	cell = ft_t_cell_add(mlx, cell, img2);
	if (!cell)
		return (NULL);
	return (cell);
}
