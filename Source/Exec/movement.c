/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:38:32 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/04 18:03:26 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

int	key_press(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	if (keycode == XK_Escape)
		exit(1);
	return 0;
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
	return 0;
}

void	check_colision(t_master *master, float x, float y)
{
	t_player	*player = master->player;

	if (master->map->map[(int)(player->player_y / BLOCK)][(int)(x / BLOCK)] == '1')
		x = player->player_x;
	player->player_x = x;
	if (master->map->map[(int)(y / BLOCK)][(int)(player->player_x / BLOCK)] == '1')
		y = player->player_y;
	player->player_y = y;
}

void	movement(t_master *master, float c, float s, float speed)
{
	t_player	*player = master->player;
	float		new_x = player->player_x;
	float		new_y = player->player_y;
	if (player->key_up)
	{
		new_x += c * speed;
		new_y += s * speed;
	}
	if (player->key_down)
	{
		new_x -= c * speed;
		new_y -= s * speed;
	}
	if (player->key_left)
	{
		new_x += s * speed;
		new_y -= c * speed;
	} 
	if (player->key_right)
	{
		new_x -= s * speed;
		new_y += c * speed;
	}
	check_colision(master, new_x, new_y);
}

void	move_player(t_master *master)
{
	t_player	*player = master->player;
	int	speed = 2;
	float	angle_speed = 0.09;
	float	cos_angle = cos(player->angle);
	float	sin_angle = sin(player->angle);

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
