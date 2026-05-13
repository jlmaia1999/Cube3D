/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:52:46 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/13 15:33:24 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

int	get_color(t_image *img, int x, int y)
{
	int	offset;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= img->width)
		x = img->width - 1;
	if (y >= img->height)
		y = img->height - 1;
	offset = y * img->size_line + x * img->bpp / 8;
	return (*(int *)(img->adress + offset));
}

int	get_x(t_master *master, float dist, int side, int tex_dir)
{
	float	wall;
	int		x;

	if (side == 0)
		wall = (master->player->player_y / BLOCK) \
+ dist * master->ray->ray_dir_y;
	else
		wall = (master->player->player_x / BLOCK) \
+ dist * master->ray->ray_dir_x;
	wall -= floor(wall);
	x = (int)(wall * master->textures->t_array[tex_dir].width);
	if (side == 0 && master->ray->ray_dir_x < 0)
		x = master->textures->t_array[tex_dir].width - x - 1;
	if (side == 1 && master->ray->ray_dir_y > 0)
		x = master->textures->t_array[tex_dir].width - x - 1;
	return (x);
}

int	get_texture_dir(t_master *master)
{
	int	side;

	side = master->ray->side;
	if (side == 1)
	{
		if (master->ray->ray_dir_y > 0)
			return (NO);
		return (SO);
	}
	else
	{
		if (master->ray->ray_dir_x > 0)
			return (WE);
		return (EA);
	}
}

void	draw_tex(t_master *master, int x, int start, int end)
{
	float	dist;
	float	step;
	float	pos;
	int		i;
	int		dir;

	if (master->ray->side)
		dist = master->ray->side_dist_y - master->ray->delta_dist_y;
	else
		dist = master->ray->side_dist_x - master->ray->delta_dist_x;
	i = get_x(master, dist, master->ray->side, get_texture_dir(master));
	dir = get_texture_dir(master);
	step = (float)master->textures->t_array[get_texture_dir(master)].height / \
(float)(end - start + 1);
	pos = 0.0f;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (start <= end)
	{
		put_pixel(x, start, get_color(&master->textures->t_array[dir], i, \
(int)pos), master->image);
		pos += step;
		start++;
	}
}
