#include "../../Includes/parsing.h"

void	set_angle(t_player *player)
{

	if (player->player_dir == 'S')
		player->angle = PI / 2;
	else if(player->player_dir == 'N')
		player->angle = 3 * PI / 2;
	else if(player->player_dir == 'W')
		player->angle = PI;
	else if(player->player_dir == 'E')
		player->angle = 0;
}

void	init_player(t_player *player)
{
	set_angle(player);
	player->key_down = false;
	player->key_up = false;
	player->key_left = false;
	player->key_right = false;
	player->right_rotate = false;
	player->left_rotate = false;
}