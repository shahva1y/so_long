#ifndef IMG_H
# define IMG_H
# define IMG_WIDTH 50
# define IMG_HEIGHT 50

# define IMG_WALL "./img/wall.xpm"
# define IMG_SPACE "./img/space.xpm"
# define IMG_EXIT "./img/exit.xpm"
# define IMG_ITEM "./img/item0.xpm"
# define IMG_HERO_RIGHT "./img/hero_right0.xpm"
# define IMG_HERO_LEFT "./img/hero_left0.xpm"
# define IMG_HERO_UP "./img/hero_up0.xpm"

typedef struct s_img
{
	void	*wall;
	void	*space;
	void	*items;
	void	*exit;
	void	*hero_dir[3];
	void	*hero;
}			t_img;

#endif