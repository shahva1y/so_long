#ifndef IMG_H
# define IMG_H
# define IMG_WIDTH 50
# define IMG_HEIGHT 50

# define IMG_WALL "./img/wall.xpm"
# define IMG_SPACE "./img/space.xpm"
# define IMG_EXIT "./img/exit.xpm"

# define IMG_ITEM0 "./img/item0.xpm"
# define IMG_ITEM1 "./img/item1.xpm"
# define IMG_ITEM2 "./img/item2.xpm"

# define IMG_HERO_UP0 "./img/hero_up0.xpm"
# define IMG_HERO_UP1 "./img/hero_up1.xpm"
# define IMG_HERO_UP2 "./img/hero_up2.xpm"

# define IMG_HERO_RIGHT0 "./img/hero_right0.xpm"
# define IMG_HERO_RIGHT1 "./img/hero_right1.xpm"
# define IMG_HERO_RIGHT2 "./img/hero_right2.xpm"

# define IMG_HERO_LEFT0 "./img/hero_left0.xpm"
# define IMG_HERO_LEFT1 "./img/hero_left1.xpm"
# define IMG_HERO_LEFT2 "./img/hero_left2.xpm"

# define IMG_ENEMY0 "./img/enemy0.xpm"
# define IMG_ENEMY1 "./img/enemy1.xpm"
# define IMG_ENEMY2 "./img/enemy2.xpm"

typedef struct s_cell
{
	void			*img;
	struct s_cell	*next;
}			t_cell;

typedef struct s_img
{
	void	*wall;
	void	*space;
	void	*exit;
	t_cell	*items;
	t_cell	*hero;
	t_cell	*hero_dir[3];
	t_cell	*enemy;
	int		tick;
}			t_img;

#endif