/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:40:13 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/13 14:40:14 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

void	background(t_master *master)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT / 2)
	{
		i = 0;
		while (i < WIDTH)
		{
			put_pixel(i, j, master->textures->ceiling_hex, master->image);
			i++;
		}
		j++;
	}
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			put_pixel(i, j, master->textures->floor_hex, master->image);
			i++;
		}
		j++;
	}
}
