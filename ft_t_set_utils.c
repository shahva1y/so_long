#include "so_long.h"

t_set	*ft_init_t_set(t_meta *meta, t_mlx *mlx, t_img *img)
{
	t_set	*set;

	set = malloc(sizeof(t_set));
	if (!set)
	{
		ft_error("t_set init error!");
		return (NULL);
	}
	set->meta = meta;
	set->mlx = mlx;
	set->img = img;
	return (set);
}

void	ft_free_t_set(t_set *set)
{
	if (set)
	{
		ft_free_t_meta(set->meta);
		ft_free_t_mlx(set->mlx);
		ft_free_t_img(set->img);
		free(set);
	}
}
