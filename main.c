#include "so_long.h"

int	main(int argc, char **argv)
{
	t_set	*set;
	t_meta	*meta;
	t_mlx	*mlx;
	t_img	*img;

	if (argc != 2)
	{
		ft_error("Usage: ./so_long file_name.ber");
		return (1);
	}
	meta = ft_parse_file(argv[1]);
	mlx = ft_init_t_mlx(meta);
	img = ft_init_t_img(mlx);
	if (!meta || !mlx || !img)
		ft_error_exit(meta, mlx, img);
	set = ft_init_t_set(meta, mlx, img);
	if (!set)
		ft_error_exit(meta, mlx, img);
	mlx_hook(mlx->win, 2, 0, ft_key_press, set);
	mlx_loop_hook(mlx->mlx, ft_frame_update, set);
	mlx_hook(mlx->win, 17, 0, ft_exit, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
