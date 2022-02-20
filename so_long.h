#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

void	ft_error(char *error_messege);
void	ft_valid(t_mlx *mlx, int argc, char **argv);

#endif