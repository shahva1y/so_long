#include "so_long.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	ft_free_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
