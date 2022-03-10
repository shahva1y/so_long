#include "so_long_bonus.h"

void	ft_destroy_t_cell(t_mlx *mlx, t_cell *cell)
{
	t_cell	*tmp;
	t_cell	*cur;

	if (cell)
	{
		tmp = cell->next;
		while (tmp != cell)
		{
			mlx_destroy_image(mlx->mlx, tmp->img);
			cur = tmp;
			tmp = tmp->next;
			ft_free(cur);
		}
		mlx_destroy_image(mlx->mlx, tmp->img);
		ft_free(tmp);
	}
}

t_cell	*ft_t_cell_add(t_mlx *mlx, t_cell *cell, char *img)
{
	t_cell	*node;
	t_cell	*tmp;

	node = malloc(sizeof(t_cell));
	if (!node)
	{
		ft_error("memory allocation error! (t_list)");
		ft_destroy_t_cell(mlx->mlx, cell);
		return (NULL);
	}
	node->img = img;
	node->next = node;
	if (!cell)
		cell = node;
	else
	{
		tmp = cell;
		while (tmp->next != cell)
			tmp = tmp->next;
		tmp->next = node;
		node->next = cell;
	}
	return (cell);
}
