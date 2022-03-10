#include "so_long_bonus.h"

static void	ft_define_t_hero(t_hero *hero, char **array)
{
	int		i;
	int		j;

	hero->x = -1;
	hero->y = -1;
	hero->items = 0;
	hero->steps = 0;
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'P')
			{
				hero->x = j;
				hero->y = i;
			}
			else if (array[i][j] == 'C')
				(hero->items)++;
			j++;
		}
		i++;
	}
}

t_hero	*ft_init_t_hero(char **array)
{
	t_hero	*hero;

	hero = malloc(sizeof(t_hero));
	if (!hero)
	{
		ft_error("t_hero init error!");
		return (NULL);
	}
	ft_define_t_hero(hero, array);
	return (hero);
}
