#include "cube3D_exec.h"

int	main(void)
{
	t_game	game;

	init_game(&game);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
	mlx_hook(game.win, 3, 1l<<1, key_release, &game.player);

	mlx_loop_hook(game.mlx, draw_loop, &game);
	
}