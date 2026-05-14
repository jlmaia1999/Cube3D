/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:35:59 by diogo             #+#    #+#             */
/*   Updated: 2026/05/14 20:11:12 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

void	free_array(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	error_exit(t_master **master, char *error)
{
	ft_putstr_fd (error, 2);
	clean_n_exit (master, 0);
	exit (1);
}

void	clean_n_exit2(t_master **master, int fd)
{
	if ((*master)->image)
	{
		if ((*master)->image->img)
			mlx_destroy_image ((*master)->mlx, (*master)->image->img);
		free ((*master)->image);
	}
	if ((*master)->ray)
		free ((*master)->ray);
	if ((*master)->player)
		free ((*master)->player);
	if ((*master)->win)
		mlx_destroy_window((*master)->mlx, (*master)->win);
	if ((*master)->mlx)
	{
		mlx_destroy_display((*master)->mlx);
		free ((*master)->mlx);
	}
	if (fd)
		close (fd);
	free (*master);
	exit (0);
}

void	clean_n_exit(t_master **master, int fd)
{
	int	i;

	i = 0;
	if ((*master)->map->file)
		free_array((*master)->map->file);
	if ((*master)->map->map)
		free_array((*master)->map->map);
	free ((*master)->map);
	if ((*master)->textures->t_strings[NO])
		free((*master)->textures->t_strings[NO]);
	if ((*master)->textures->t_strings[SO])
		free((*master)->textures->t_strings[SO]);
	if ((*master)->textures->t_strings[EA])
		free((*master)->textures->t_strings[EA]);
	if ((*master)->textures->t_strings[WE])
		free((*master)->textures->t_strings[WE]);
	while (i < 4)
	{
		if ((*master)->textures->t_array[i].img)
			mlx_destroy_image((*master)->mlx, \
(*master)->textures->t_array[i].img);
		i++;
	}
	free ((*master)->textures);
	clean_n_exit2(master, fd);
}
