#include "parsing.h"

int	long_row_finder(char **map, int i)
{
	int row_size;
	int big;
	int big_row_size;

	big = 0;
	big_row_size = 0;
	while (map[i])
	{
		row_size = 0;
		while (map[i][row_size])
		{
			row_size++;
		}
		if (row_size > big_row_size)
		{
			big_row_size = row_size;
		}
		i++;
	}
	return (big_row_size);
}

int	sv_map(int i, t_master *master)
{
	int j;
	int longest_row;

	j = 0;
	while (master->map->file[i + j])
		j++;
	master->map->map = ft_calloc (sizeof(char *), (j + 2));
	if (!master->map->map)
		return (ft_putstr_fd ("ERROR\nMalloc error\n", 2), 1);
	j = 0;
	longest_row = long_row_finder(master->map->file, i);
	printf("%d\n", longest_row);
	while (master->map->file[i + j])
	{
		master->map->map[j] = ft_calloc(longest_row + 1, 1);
		ft_memset (master->map->map[j], ' ', longest_row);
		j++;
	}
	j = 0;
	while (master->map->map[j])
	{
		ft_memcpy (master->map->map[j], master->map->file[i + j], ft_strlen(master->map->file[i + j]) + 1);
		j++;
	}
	return (0);
}

int	map_extractor(t_master *master)
{
	int	i;

	i = 0;
	while (master->map->file[i])
	{
		if (master->map->file[i][0] == '1' || master->map->file[i][0] == ' ')
			break ;
		i++;
	}
	if (!master->map->file[i])
		return (ft_putstr_fd(ERR_NO_MAP, 2), 1);
	if (sv_map (i, master))
		return (1);
	free_array (master->map->file);
	if (map_parser(master->map->map))
		return (1);
	return (0);
	
}
