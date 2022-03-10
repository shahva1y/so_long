#include "so_long_bonus.h"

static t_bool	ft_line_iswall(char	*line)
{
	int	i;

	i = 0;
	while (line[i] == '1')
		i++;
	if (line[i] == '\0' && i != 0)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_check_walls(t_list	*list)
{
	unsigned int		width;

	width = ft_strlen(list->line);
	if (!ft_line_iswall(list->line))
		return (FALSE);
	while (list->next != NULL)
	{
		if (width != ft_strlen(list->line))
			return (FALSE);
		if ((list->line)[0] != '1' || (list->line)[width - 1] != '1')
			return (FALSE);
		list = list->next;
	}
	if (!ft_line_iswall(list->line) || width != ft_strlen(list->line))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_check_line(char *row, t_count *count)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] == 'P')
			count->hero += 1;
		else if (row[i] == 'E')
			count->exits += 1;
		else if (row[i] == 'C')
			count->items += 1;
		else if (row[i] != '1' && row[i] != '0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ft_check_inside(t_list *list)
{
	t_count	count;

	count.items = 0;
	count.exits = 0;
	count.hero = 0;
	while (list->next != NULL)
	{
		if (!ft_check_line(list->line, &count))
		{
			ft_error("not exist char!");
			return (FALSE);
		}
		list = list->next;
	}
	if (count.hero != 1)
		ft_error("incorrect number of players!");
	if (count.items < 1)
		ft_error("no items!");
	if (count.exits < 1)
		ft_error("no exits!");
	if ((count.hero != 1) || (count.items < 1) || (count.exits < 1))
		return (FALSE);
	return (TRUE);
}
