/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:52:46 by jomaia            #+#    #+#             */
/*   Updated: 2026/04/29 17:06:18 by jomaia           ###   ########.fr       */
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
	offset = y * img->size_line + x * (img->bpp / 8);
	return (*(int *)(img->adress + offset));
}

int	get_x(t_master *master, float dist, int side, int tex_dir)
{
	float	wall;
	int		x;

	if (side == 0)
		wall = (master->player->player_y / BLOCK) + dist * master->ray->ray_dir_y;
	else
		wall = (master->player->player_x / BLOCK) + dist * master->ray->ray_dir_x;
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
			return (SO);
		return (NO);
	}
	else
	{
		if (master->ray->ray_dir_x > 0)
			return (EA);
		return (WE);
	}
}

void	draw_tex(t_master *master, int x, int start, int end)
{
	float	dist;
	float	step;
	float	pos;
	int		y;

	if (master->ray->side)
		dist = master->ray->side_dist_y - master->ray->delta_dist_y;
	else
		dist = master->ray->side_dist_x - master->ray->delta_dist_x;
	step = (float)master->textures->t_array[get_texture_dir(master)].height
	/ (float)(end - start + 1);
	pos = 0.0f;
	if (start < 0)
	{
		pos = -start * step;
		start = 0;
	}
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = start;
	while (y <= end)
	{
		put_pixel(x, y, get_color(&master->textures->t_array[get_texture_dir(master)],
	get_x(master, dist, master->ray->side, get_texture_dir(master)), pos), master->image);
		pos += step;
		y++;
	}
}
