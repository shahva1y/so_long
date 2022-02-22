#include "so_long.h"

static t_meta *ft_meta_init()
{
	t_meta	*game;

	game = NULL;
	game = (t_meta *)malloc(sizeof(t_meta));
	if (!game)
		ft_error("Memmory allocation error!");
	game->heros = 0;
	game->exits = 0;
	game->items = 0;
	game->map = NULL;
	return (game);
}

t_meta	*ft_parse_map(char **map)
{
	t_meta	*game;
	int		i;
	int		j;

	game = ft_meta_init();
	game->map = map;
	//ft_parse_map
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(game->heros)++;
			else if (map[i][j] == 'E')
				(game->exits)++;
			else if (map[i][j] == 'C')
				(game->items)++;
			j++;
		}
		i++;
	}
	if (game->heros != 1)
		ft_error("Incorrect number of players!");
	if (game->items < 1)
		ft_error("No items!");
	if (game->exits < 1)
		ft_error("No exits!");
	return (game);
}