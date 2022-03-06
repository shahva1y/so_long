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
	t_meta	*meta;

	meta = set->meta;
	if (keycode == W)
		ft_move(meta, 0, -1);
	else if (keycode == S)
		ft_move(meta, 0, +1);
	else if (keycode == A)
		ft_move(meta, -1, 0);
	else if (keycode == D)
		ft_move(meta, +1, 0);
	else if (keycode == ESC)
		ft_exit(set);
	return (0);
}
