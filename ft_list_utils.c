#include "so_long.h"

void	ft_list_add(t_node **list, char *line)
{
	t_node	*node;
	t_node	*tmp;

	node = malloc(sizeof(t_node));
	if (!node)
		ft_error("Ooooops! Memmory allocation error!");
	node->line = line;
	node->next = NULL;
	if (!(*list))
		(*list) = node;
	else
	{
		tmp = (*list);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}

unsigned int	ft_list_length(t_node *list)
{
	unsigned int	width;

	width = 0;
	while (list)
	{
		width++;
		list = list->next;
	}
	return (width);
}

char	**ft_list_to_array(t_node *list)
{
	unsigned int	height;
	char			**array;
	unsigned int	i;

	if (!list)
		return (NULL);
	height = ft_list_length(list);
	array = (char **)malloc(sizeof(char **) * (height + 1));
	if (!array)
		ft_error("Memmory allocation error!");
	//возможно отдельная функция! но тогда необходимо придумать проверки
	i = 0;
	while (list)
	{
		array[i] = list->line;
		list = list->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	ft_list_free(t_node *list)
{
	t_node	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}