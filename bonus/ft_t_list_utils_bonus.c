#include "so_long_bonus.h"

void	ft_free_t_list_with_content(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_free(tmp->line);
		ft_free(tmp);
	}
}

void	ft_free_t_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_free(tmp);
	}
}

t_list	*ft_t_list_add(t_list	*list, char *line)
{
	t_list	*node;
	t_list	*tmp;

	if (!line)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
	{
		ft_error("memory allocation error! (t_list)");
		ft_free_t_list_with_content(list);
		return (NULL);
	}
	node->line = line;
	node->next = NULL;
	if (!list)
		list = node;
	else
	{
		tmp = list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (list);
}

unsigned int	ft_t_list_length(t_list *list)
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

char	**ft_t_list_to_array(t_list *list)
{
	unsigned int	height;
	char			**array;
	unsigned int	i;

	if (!list)
		return (NULL);
	height = ft_t_list_length(list);
	array = (char **)malloc(sizeof(char **) * (height + 1));
	if (!array)
	{
		ft_error("memory allocation error! (char **)");
		return (NULL);
	}
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
