#include "so_long.h"

t_meta	*ft_parse_map(char **array)
{
	t_meta	*meta;
	t_hero	*hero;
	t_map	*map;

	map = ft_init_t_map(array);
	if (!map)
		return (NULL);
	hero = ft_init_t_hero(array);
	if (!hero)
	{
		ft_free_t_map(map);
		return (NULL);
	}
	meta = ft_init_t_meta(map, hero);
	if (!meta)
	{
		ft_free_t_map(map);
		ft_free(hero);
		return (NULL);
	}
	return (meta);
}
