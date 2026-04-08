#include "../../Includes/parsing.h"

void	init_player(t_player *player)
{
	player->player_x = WIDTH / 2;
	player->player_y = HEIGHT / 2;
	player->angle = 0;
	player->key_down = false;
	player->key_up = false;
	player->key_left = false;
	player->key_right = false;
	player->right_rotate = false;
	player->left_rotate = false;
}

void	hook_and_loop(t_master *master)
{
	mlx_hook(master->win, 2, 1L<<0, key_press, &master->player);
	mlx_hook(master->win, 3, 1L<<1, key_release, master->player);

	mlx_loop_hook(master->mlx, draw_loop, master);
}