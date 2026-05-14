/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:31:29 by diogo             #+#    #+#             */
/*   Updated: 2026/05/14 20:32:35 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/structs.h"
#include "../Includes/parsing.h"

int	main(int argc, char **argv)
{
	t_master	*master;

	master = NULL;
	master_init(&master);
	parsing(argc, argv, master);
	init_player(master->player);
	mlx_hook(master->win, 2, 1L << 0, key_press, master);
	mlx_hook(master->win, 3, 1L << 1, key_release, master->player);
	mlx_hook(master->win, 17, 0, close_game, &master);
	mlx_loop_hook(master->mlx, draw_loop, master);
	mlx_loop(master->mlx);
	clean_n_exit(&master, 0);
}
