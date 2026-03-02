#include "parsing.h"

int	check_map_cut(char *file)
{
	int in_map;
	int i;

	in_map = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '\n' && (file[i + 1] == '1' || file[i + 1] == ' '))
			in_map = 1;
		if (in_map == 1)
		{
			while (file[i])
			{
				if (file[i] == '\n' && (file[i - 1] == '1' || file[i - 1] == ' '))
				{
					if (file[i + 1] != '1' && file[i + 1] != ' ')
						return (ft_putstr_fd (ERR_MAP_SHAPE, 2), 1);
				}
				i++;
				// printf ("sou a letra n %d\n", i);
			}
		}
		if (file [i])
			i++;
	}
	return (0);
}

int	sv_map(int fd, t_master *master)
{
	char *line;
	char *map_cpy;

	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd(ERR_MAP_EMPTY, 2);
		return (1);
	}
	map_cpy = ft_strdup("");
	while (line)
	{
		map_cpy = ft_strjoin_gnl (map_cpy, line);
		free (line);
		line = get_next_line(fd);
	}
	if (check_map_cut(map_cpy))
		return (1);
	master->map->map = ft_split(map_cpy, '\n');
	free (line);
	free (map_cpy);
	return (0);
}

void	check_and_store_map(int fd, t_master *master)
{
	if (sv_map(fd, master))
		clean_n_exit(&master);
	int i = 0;
	while (master->map->map[i])
	{
		printf("%s\n", master->map->map[i]);
		i++;
	}
}
