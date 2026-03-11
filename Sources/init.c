#include "cube3D_exec.h"

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT /2;
	player->angle = 0;

	player->key_down = false;
	player->key_up = false;
	player->key_left = false;
	player->key_right = false;
	player->right_rotate = false;
	player->left_rotate = false;
}

void	int_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	
}