#include "so_long_bonus.h"

t_meta	*ft_parse_map(char **array)
{
	t_meta	*meta;
	t_hero	*hero;
	t_map	*map;
	t_enemy	*enemy;

	map = ft_init_t_map(array);
	if (!map)
		return (NULL);
	enemy = ft_init_t_enemy(array);
	hero = ft_init_t_hero(array);
	if (!hero || !enemy)
	{
		ft_free_t_map(map);
		return (NULL);
	}
	meta = ft_init_t_meta(map, hero, enemy);
	if (!meta)
	{
		ft_free_t_map(map);
		ft_free(hero);
		return (NULL);
	}
	return (meta);
}
