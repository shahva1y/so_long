#ifndef IMG_H
# define IMG_H
# define IMG_WIDTH 50
# define IMG_HEIGHT 50

# define IMG_WALL "./img/wall.xpm"
# define IMG_SPACE "./img/space.xpm"
# define IMG_EXIT "./img/exit.xpm"
# define IMG_ITEM "./img/item.xpm"
# define IMG_HERO "./img/hero.xpm"

typedef struct s_img
{
	void	*wall;
	void	*space;
	void	*items;
	void	*exit;
	void	*hero;
}			t_img;

#endif