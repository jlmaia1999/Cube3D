/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaom <joaom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:38:32 by jomaia            #+#    #+#             */
/*   Updated: 2026/08/05 02:42:21 by joaom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

int	key_press(int keycode, t_master *master)
{
	if (keycode == W)
		master->player->key_up = true;
	if (keycode == S)
		master->player->key_down = true;
	if (keycode == A)
		master->player->key_left = true;
	if (keycode == D)
		master->player->key_right = true;
	if (keycode == LEFT)
		master->player->left_rotate = true;
	if (keycode == RIGHT)
		master->player->right_rotate = true;
	if (keycode == XK_Escape)
		clean_n_exit(&master, 0);
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void	check_colision(t_master *master, float x, float y)
{
	t_player	*player;

	player = master->player;
	if (master->map->map[(int)((player->player_y + 8.0f) / BLOCK)][(int)((x + \
8.0f) / BLOCK)] == '1' || master->map->map[(int)((player->player_y + 8.0f) / \
BLOCK)][(int)((x - 8.0f) / BLOCK)] == '1' || master->map->map[(int)((player\
->player_y - 8.0f) / BLOCK)][(int)((x + 8.0f) / BLOCK)] == '1' || master->map\
->map[(int)((player->player_y - 8.0f) / BLOCK)][(int)((x - 8.0f) / BLOCK)] == \
'1')
		x = player->player_x;
	player->player_x = x;
	if (master->map->map[(int)((y + 8.0f) / BLOCK)][(int)((player->player_x + \
8.0f) / BLOCK)] == '1' || master->map->map[(int)((y - 8.0f) / BLOCK)][(int)\
((player->player_x + 8.0f) / BLOCK)] == '1' || master->map->map[(int)((y + \
8.0f) / BLOCK)][(int)((player->player_x - 8.0f) / BLOCK)] == '1' || master\
->map->map[(int)((y - 8.0f) / BLOCK)][(int)((player->player_x - 8.0f) / BLOCK)] \
== '1')
		y = player->player_y;
	player->player_y = y;
}

void	movement(t_master *master, float c, float s, float speed)
{
	float	new_pos[2];

	new_pos[0] = master->player->player_x;
	new_pos[1] = master->player->player_y;
	if (master->player->key_up)
	{
		new_pos[0] += c * speed;
		new_pos[1] += s * speed;
	}
	if (master->player->key_down)
	{
		new_pos[0] -= c * speed;
		new_pos[1] -= s * speed;
	}
	if (master->player->key_left)
	{
		new_pos[0] += s * speed;
		new_pos[1] -= c * speed;
	}
	if (master->player->key_right)
	{
		new_pos[0] -= s * speed;
		new_pos[1] += c * speed;
	}
	check_colision(master, new_pos[0], new_pos[1]);
}

void	move_player(t_master *master)
{
	t_player	*player;
	int			speed;
	float		angle_speed;
	float		cos_angle;
	float		sin_angle;

	player = master->player;
	speed = 1;
	angle_speed = 0.01;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	movement(master, cos_angle, sin_angle, speed);
}
