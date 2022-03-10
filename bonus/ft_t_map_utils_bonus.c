#include "so_long_bonus.h"

void	ft_free_t_map(t_map *map)
{
	if (map)
	{
		ft_free_array(map->map);
		free(map);
	}
}

t_map	*ft_init_t_map(char **array)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_error("memory allocation error! (t_map)");
		return (NULL);
	}
	map->map = array;
	map->width = (int) ft_strlen(array[0]);
	map->height = 0;
	while (array[map->height])
		(map->height)++;
	return (map);
}
