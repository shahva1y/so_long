#include "so_long.h"

void	ft_free_t_meta(t_meta *meta)
{
	if (meta)
	{
		ft_free_t_map(meta->map);
		ft_free(meta->hero);
		ft_free(meta);
	}
}

t_meta	*ft_init_t_meta(t_map *map, t_hero *hero)
{
	t_meta	*meta;

	meta = NULL;
	meta = (t_meta *)malloc(sizeof(t_meta));
	if (!meta)
	{
		ft_error("memory allocation error! (t_meta)");
		return (NULL);
	}
	meta->hero = hero;
	meta->map = map;
	return (meta);
}
