/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txs_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:36:05 by diogo             #+#    #+#             */
/*   Updated: 2026/08/04 20:22:41 by diomende         ###   ########.fr       */
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
		return (1);
	if (!ft_isdigit(texture[i]))
		return (1);
	if (texture[ft_strlen(texture) - 1] == ',')
	{
		*dir = -1;
		return (0);
	}
	rgb = ft_split (&texture[i], ',');
	*dir = rgb_to_hex(rgb);
	free_array (rgb);
	return (0);
}

int	sv_texture(char *texture, char **path)
{
	int	i;

	i = 0;
	if (*path == NULL)
	{
		if (texture[2] != ' ')
			return (1);
		while (texture[i] != ' ')
			i++;
		if (!texture[i])
			return (1);
		while (texture[i] == ' ')
			i++;
		if (!texture[i])
			return (1);
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
	int	i;

	i = 0;
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
	while (master->map->file[i])
	{
		if ((master->map->file[i][0] != 'N' || master->map->file[i][1] != 'O') && (master\
->map->file[i][0] != 'S' || master->map->file[i][1] != 'O') && (master->\
map->file[i][0] != 'W' || master->map->file[i][1] != 'E') && (master->\
map->file[i][0] != 'E' || master->map->file[i][1] != 'A') && (master->\
map->file[i][0] != 'F' && master->map->file[i][0] != 'C' && master->map->file[i][0] != ' ' \
&& master->map->file[i][0] != '\n' && master->map->file[i][0] != '1'))
			return (ft_putstr_fd(ERR_MAP_SHAPE, 2), 1);
		i++;
	}
	return (0);
}
