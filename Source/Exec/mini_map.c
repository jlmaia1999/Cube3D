/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:26:20 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/13 14:30:27 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

void	draw_square(int x, int y, int color, t_master *master)
{
	int	i;
	int	size;

	size = BLOCK;
	i = 0;
	while (i < size)
		put_pixel(x + i++, y, color, master->image);
	i = 0;
	while (i < size)
		put_pixel(x, y + i++, color, master->image);
	i = 0;
	while (i < size)
		put_pixel(x + size, y + i++, color, master->image);
	i = 0;
	while (i < size)
		put_pixel(x + i++, y + size, color, master->image);
}

void	draw_floor(int x, int y, int color, t_master *master)
{
	int	i;
	int	j;
	int	size;

	size = BLOCK;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(x + j, y + i, color, master->image);
			j++;
		}
		i++;
	}
}

void	draw_map(t_master *master)
{
	int		x;
	int		y;
	int		wallcolor;
	int		floorcolor;

	x = 0;
	y = 0;
	wallcolor = 0x0000DD;
	floorcolor = 0xAAAAAA;
	while (master->map->map[y])
	{
		x = 0;
		while (master->map->map[y][x])
		{
			if (master->map->map[y][x] == '1')
				draw_square(x * BLOCK, y * BLOCK, wallcolor, master);
			else
				draw_floor(x * BLOCK, y * BLOCK, floorcolor, master);
			x++;
		}
		y++;
	}
}
