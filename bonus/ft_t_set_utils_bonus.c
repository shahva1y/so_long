#include "so_long_bonus.h"

t_set	*ft_init_t_set(t_meta *meta, t_mlx *mlx, t_img *img)
{
	t_set	*set;

	set = malloc(sizeof(t_set));
	if (!set)
	{
		ft_error("memory allocation error! (t_set)");
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
		ft_destroy_t_img(set->mlx, set->img);
		ft_destroy_t_mlx(set->mlx);
		free(set);
	}
}
