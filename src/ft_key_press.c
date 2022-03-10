#include "so_long.h"

static t_bool	ft_check_direct(char symbol, int items)
{
	if ((symbol != '1' && symbol != 'E')
		|| (symbol == 'E' && items == 0))
		return (TRUE);
	return (FALSE);
}

static void	ft_move(t_meta *meta, int dx, int dy)
{
	int		x;
	int		y;
	char	**map;
	int		items;

	x = (meta->hero)->x;
	y = (meta->hero)->y;
	map = (meta->map)->map;
	items = (meta->hero)->items;
	if (ft_check_direct(map[y + dy][x + dx], items))
	{
		if (map[y + dy][x + dx] == 'E' && (meta->hero)->items == 0)
			exit(0);
		(meta->hero)->steps += 1;
		ft_printf("%d\n", (meta->hero)->steps);
		if (map[y + dy][x + dx] == 'C')
			(meta->hero)->items -= 1;
		map[y][x] = '0';
		map[y + dy][x + dx] = 'P';
		(meta->hero)->x += dx;
		(meta->hero)->y += dy;
	}
}

int	ft_key_press(int keycode, t_set *set)
{
	if (keycode == W)
	{
		(set->img)->hero = ((set->img)->hero_dir)[2];
		ft_move(set->meta, 0, -1);
	}
	else if (keycode == S)
	{
		(set->img)->hero = ((set->img)->hero_dir)[0];
		ft_move(set->meta, 0, +1);
	}
	else if (keycode == A)
	{
		(set->img)->hero = ((set->img)->hero_dir)[1];
		ft_move(set->meta, -1, 0);
	}
	else if (keycode == D)
	{
		(set->img)->hero = ((set->img)->hero_dir)[0];
		ft_move(set->meta, +1, 0);
	}
	else if (keycode == ESC)
		ft_exit(set);
	return (0);
}
