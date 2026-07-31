/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txs_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:36:05 by diogo             #+#    #+#             */
/*   Updated: 2026/07/31 17:28:25 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

int	rgb_to_hex(char **rgb)
{
	int	r;
	int	g;
	int	b;

	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (-1);
	r = ft_atoi_rgb(rgb[0]);
	g = ft_atoi_rgb(rgb[1]);
	b = ft_atoi_rgb(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}

int	sv_hex(char *texture, int *dir)
{
	int		i;
	char	**rgb;

	i = 0;
	if (*dir > 0)
		return (1);
	while (texture[i] != ' ' && texture[i])
		i++;
	while (texture[i] == ' ')
		i++;
	if (!texture[i])
		return (0);
	if (!ft_isdigit(texture[i]))
		return (0);
	rgb = ft_split (&texture[i], ',');
	*dir = rgb_to_hex(rgb);
	if (*dir == -1)
	{
		free_array (rgb);
		return (0);
	}
	free_array (rgb);
	return (0);
}

int	sv_texture(char *texture, char **path)
{
	int	i;

	i = 0;
	if (texture[2] != ' ')
		return (0);
	if (*path == NULL)
	{
		while (texture[i] != ' ')
			i++;
		if (!texture[i])
			return (0);
		while (texture[i] == ' ')
			i++;
		if (!texture[i])
			return (0);
		*path = ft_substr (texture, i, ft_strlen(texture));
		return (0);
	}
	return (1);
}

int	extract_textures2(t_map *map, t_textures *tex, int i)
{
	while (map->file[i])
	{
		if (map->file[i][0] == 'N' && map->file[i][1] == 'O')
			if (sv_texture(map->file[i], &tex->t_strings[NO]))
				return (ft_putstr_fd (ERR_TXS_DUP, 2), 1);
		if (map->file[i][0] == 'S' && map->file[i][1] == 'O')
			if (sv_texture(map->file[i], &tex->t_strings[SO]))
				return (ft_putstr_fd (ERR_TXS_DUP, 2), 1);
		if (map->file[i][0] == 'W' && map->file[i][1] == 'E')
			if (sv_texture(map->file[i], &tex->t_strings[WE]))
				return (ft_putstr_fd (ERR_TXS_DUP, 2), 1);
		if (map->file[i][0] == 'E' && map->file[i][1] == 'A')
			if (sv_texture(map->file[i], &tex->t_strings[EA]))
				return (ft_putstr_fd (ERR_TXS_DUP, 2), 1);
		if (map->file[i][0] == 'F')
			if (sv_hex(map->file[i], &tex->floor_hex))
				return (ft_putstr_fd (ERR_RGB_DUP, 2), 1);
		if (map->file[i][0] == 'C')
			if (sv_hex(map->file[i], &tex->ceiling_hex))
				return (ft_putstr_fd (ERR_RGB_DUP, 2), 1);
		i++;
	}
	return (0);
}

int	extract_textures(t_master *master)
{
	if (extract_textures2(master->map, master->textures, 0))
		return (1);
	if (!master->textures->t_strings[NO] || !master->textures->\
t_strings[SO] || !master->textures->t_strings[EA] || !master->\
textures->t_strings[WE] || master->textures->\
ceiling_hex == -2 || master->textures->floor_hex == -2)
		return (ft_putstr_fd (ERR_TXS_MISS, 2), 1);
	else if (master->textures->ceiling_hex == -1 || master->\
textures->floor_hex == -1)
		return (ft_putstr_fd (ERR_RGB, 2), 1);
	return (0);
}
