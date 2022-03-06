#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include "img.h"
# include "keys.h"

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

typedef struct s_hero
{
	int	x;
	int	y;
	int	items;
	int	steps;
}				t_hero;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}			t_map;

typedef struct s_meta
{
	t_hero	*hero;
	t_map	*map;
}			t_meta;

typedef struct s_set
{
	t_mlx	*mlx;
	t_meta	*meta;
	t_img	*img;
}	t_set;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct s_count
{
	int	items;
	int	exits;
	int	hero;
}	t_count;

void	ft_error(char *error_messege);
t_meta	*ft_parse_file(char *file);
char	**ft_read_file(int fd);
t_meta	*ft_parse_map(char **map);

int		ft_get_next_line(int fd, char **buffer);

t_bool	ft_check_line(char *row, t_count *count);
t_bool	ft_check_walls(t_list	*list);
t_bool	ft_check_inside(t_list *list);

t_list	*ft_t_list_add(t_list *list, char *line);
char	**ft_t_list_to_array(t_list *list);

int		ft_key_press(int keycode, t_set *set);

int		ft_frame_update(t_set *set);

t_mlx	*ft_init_t_mlx(t_meta *meta);
t_img	*ft_init_t_img(t_mlx *mlx);
t_meta	*ft_init_t_meta(t_map *map, t_hero *hero);
t_map	*ft_init_t_map(char **array);
t_hero	*ft_init_t_hero(char **array);
t_set	*ft_init_t_set(t_meta *meta, t_mlx *mlx, t_img *img);

void	ft_free(void *ptr);
void	ft_free_t_set(t_set *set);
void	ft_free_t_mlx(t_mlx *mlx);
void	ft_free_t_meta(t_meta *meta);
void	ft_free_t_img(t_img *img);
void	ft_free_t_map(t_map *map);
void	ft_free_t_list(t_list *list);
void	ft_free_t_list_with_content(t_list *list);
void	ft_free_array(char **array);

int		ft_exit(t_set *set);
void	ft_error_exit(t_meta *meta, t_mlx *mlx, t_img *img);

#endif