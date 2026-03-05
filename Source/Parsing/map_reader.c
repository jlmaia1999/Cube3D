#include "parsing.h"

int is_nl_valid(char *file, int i)
{
	while (file[i])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
		{
			while (file[i] == '\n')
				i++;
			if (!file [i])
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_cut(char *file)
{
	int in_map;
	int i;

	in_map = 0;
	i = 0;
	while (file[i])
	{
		if (in_map == 1)
		{
			if (is_nl_valid (file, i))
				return (0);
			else
				return (ft_putstr_fd (ERR_MAP_SHAPE, 2), 1);
		}
		if (file[i] == '\n' && (file[i + 1] == '1' || file[i + 1] == ' '))
			in_map = 1;
		i++;
	}
	return (0);
}

int	sv_file(int fd, t_master *master)
{
	char *line;
	char *file_cpy;

	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd(ERR_MAP_EMPTY, 2);
		return (1);
	}
	file_cpy = ft_strdup("");
	while (line)
	{
		file_cpy = ft_strjoin_gnl (file_cpy, line);
		free (line);
		line = get_next_line(fd);
	}
	if (check_map_cut(file_cpy))
		return (1);
	master->map->file = ft_split(file_cpy, '\n');
	free (line);
	free (file_cpy);
	return (0);
}

void	sv_player_orientation(char **map, t_master *master)
{
	
}

void	check_and_store_map(int fd, t_master *master)
{
	if (sv_file(fd, master))
		clean_n_exit(&master);
	if (extract_textures(master))
		clean_n_exit(&master);
	if (parse_textures(master->textures))
		clean_n_exit(&master);
	if (map_extractor (master))
		clean_n_exit(&master);
	sv_player_orientation(master->map->map, master);
	// printf("%s\n", master->textures->n_texture);
	// printf("%s\n", master->textures->s_texture);
	// printf("%s\n", master->textures->w_texture);
	// printf("%s\n", master->textures->e_texture);
	// printf("%X\n", master->textures->floor_hex);
	// printf("%X\n", master->textures->ceiling_hex);
	int i = 0;
	while (master->map->map[i])
	{
		printf("%s\n", master->map->map[i]);
		i++;
	}
}
