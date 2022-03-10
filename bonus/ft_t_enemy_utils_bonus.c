#include "so_long_bonus.h"

static unsigned int	ft_random(t_enemy *enemy)
{
	unsigned int	next;

	(enemy->rand) = (enemy->rand) * 1103515245 + 12345;
	(enemy->rand) = ((enemy->rand) / 65536) % 32768;
	next = (enemy->rand) % 4;
	return (next);
}

t_bool	ft_move_t_enemy(t_enemy *enemy, t_map *map)
{
	int				dx;
	int				dy;
	unsigned int	next;

	dx = 0;
	dy = 0;
	next = ft_random(enemy);
	if (next == 0)
		dx = 1;
	else if (next == 1)
		dx = -1;
	else if (next == 2)
		dy = 1;
	else if (next == 3)
		dy = -1;
	if ((map->map)[(enemy->y) + dy][(enemy->x) + dx] == '0')
	{
		(map->map)[enemy->y][enemy->x] = '0';
		(map->map)[(enemy->y) + dy][(enemy->x) + dx] = 'X';
		enemy->x = (enemy->x) + dx;
		enemy->y = (enemy->y) + dy;
	}
	else if ((map->map)[(enemy->y) + dy][(enemy->x) + dx] == 'P')
		return (FALSE);
	return (TRUE);
}

static void	ft_define_t_enemy(t_enemy *enemy, char **array)
{
	int	x;
	int	y;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x] && array[y][x] != '0')
			x++;
		if (array[y][x] == '0')
		{
			array[y][x] = 'X';
			break ;
		}
		y++;
	}
	enemy->x = x;
	enemy->y = y;
	enemy->rand = 1;
}

t_enemy	*ft_init_t_enemy(char	**array)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
	{
		ft_error("memmory allocation error! (t_enemy)");
		return (NULL);
	}
	ft_define_t_enemy(enemy, array);
	return (enemy);
}
