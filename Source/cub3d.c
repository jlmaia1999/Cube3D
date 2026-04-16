#include "../Includes/structs.h"
#include "../Includes/parsing.h"

int	main(int argc, char **argv)
{
	t_master *master;

	master = NULL;
	master_init(&master);

	parsing(argc, argv, master);
	init_player(master->player);
	mlx_hook(master->win, 2, 1L<<0, key_press, master->player);
	mlx_hook(master->win, 3, 1L<<1, key_release, master->player);
	mlx_loop_hook(master->mlx, draw_loop, master);

	mlx_loop(master->mlx);
	clean_n_exit(&master, 0);
}