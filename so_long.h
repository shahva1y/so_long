#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_meta
{
	int		heros;
	int		items;
	int		exits;
	char	**map;
} t_meta;

typedef struct s_node
{
	char			*line;
	struct s_node	*next;
} t_node;

void	ft_error(char *error_messege);
t_meta	*ft_process_args(int argc, char **argv);
char	**ft_parse_file(int fd);
t_meta	*ft_parse_map(char **map);

void	ft_list_add(t_node **list, char *line);
char	**ft_list_to_array(t_node *list);
void	ft_list_free(t_node *list);

#endif