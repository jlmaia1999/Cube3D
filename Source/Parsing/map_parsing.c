#include "parsing.h"

int	map_ext_check(char *av)
{
	int	len;
	len = ft_strlen(av);

	if (len < 5 || ft_strnstr (av, ".cub", len) == NULL)
		return (1);
	if (ft_strncmp(&av[len - 4], ".cub", 4) || av[len - 5] == '/')
		return (1);
	return (0);
}

int	is_closed(char *row, int i)
{
	int j;

	j = 1;
	// if (!row[i + j] || !row[i - j])
	// 	return (0);
	while (row [i - j])
	{
		if (row [i - j] == '1')
			break ;
		if (row [i - j] == ' ')
			return (0);
		j++;
	}
	if (!row[i - j])
		return (0);
	j = 1;
	while (row [i + j])
	{
		if (row [i + j] == '1')
			break ;
		if (row [i + j] == ' ')
			return (0);
		j++;
	}
	if (!row[i + j])
		return (0);
	return (1);
}

int	parse_row_border(char *row)
{
	int i;

	i = 0;
	while (row[i])
	{
		while (row[i] == '1' || row[i] == ' ')
			i++;
		if (row[i] != '1' && row[i] != ' ')
		{
			if (!is_closed (row, i))
				return (1);
		}
		i++;
	}
	return (0);
}

int	parse_borders(char **map)
{
	int i;
	int j;

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
		if(parse_row_border(map[i]))
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
	int i;
	int j;
	int player;

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