#include <stdio.h>

#include "so_long.h"

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_meta	*game;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	game = ft_process_args(argc, argv);

	/*
	установка соединения с провильной графической системой
	окно еще не создается
	*/
	mlx->mlx = mlx_init();
	/*
	 * инициализация крошечного окна
	 * закрыть можно будет через терминал ctrl+C
	 * эта функция вернет указатель на окно, которое мы создали
	 * */
	int	width = (int) ft_strlen((game->map)[0]);
	int	height = 0;
	while (game->map[height])
		height++;
	mlx->win = mlx_new_window(mlx, width * 50,  height * 50, "so_long");

	//mlx_hook(mlx_win, );
	// mlx_loop() инициализирует рендеринг окна
	/*
	 * Бесконечный цикл, который держит программу запущенной,
	 * окно открытым и будет продолжать обнаруживать различные события
	 * и вызывать функции, которые мы к ним подключили (?)
	 * Любой код, после этой функции не будет выполнен!
	 * */
	mlx_loop(mlx);

	return (0);
}
