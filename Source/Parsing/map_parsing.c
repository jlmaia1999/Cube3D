/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:35:48 by diogo             #+#    #+#             */
/*   Updated: 2026/05/14 19:54:59 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

int	is_col_closed(char **map, int row, int col)
{
	if (!map[row - 1])
		return (0);
	if (!map[row + 1])
		return (0);
	if (map[row + 1][col] == ' ' || map[row - 1][col] == ' ')
		return (0);
	return (1);
}

int	parse_row_border(char *row, char **map, int row_nbr)
{
	int	i;

	i = 0;
	while (row[i])
	{
		while (row[i] == '1' || row[i] == ' ')
			i++;
		if (row[i] != '1' && row[i] != ' ' && row[i])
		{
			if (!is_row_closed (row, i))
				return (1);
			if (!is_col_closed(map, row_nbr, i))
				return (1);
			i++;
		}
	}
	return (0);
}

int	parse_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (1);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if (parse_row_border(map[i], map, i))
			return (1);
		i++;
	}
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1' && map[i - 1][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

int	parse_map_elements(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ' || map[i][j] == '0')
				j++;
			else if (map[i][j] == 'N' || map[i][j] == 'S' \
|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player++;
				j++;
			}
			else
				return (1);
		}
		i++;
	}
	return (player < 1 || player > 1);
}

int	map_parser(char **map)
{
	if (parse_map_elements(map))
		return (ft_putstr_fd(ERR_MAP_ELEM, 2), 1);
	if (parse_borders(map))
		return (ft_putstr_fd(ERR_MAP_OPEN, 2), 1);
	return (0);
}
