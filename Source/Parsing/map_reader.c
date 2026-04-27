#include "../../Includes/parsing.h"

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
			{
				free (file);
				return (ft_putstr_fd (ERR_MAP_SHAPE, 2), 1);
			}
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

int	sv_player_orientation(char **map, t_player *p)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return (p->player_x = j*BLOCK, p->player_y = i*BLOCK, p->player_dir = 'N');
			if (map[i][j] == 'S')
				return (p->player_x = j*BLOCK, p->player_y = i*BLOCK, p->player_dir = 'S');
			if (map[i][j] == 'E')
				return (p->player_x = j*BLOCK, p->player_y = i*BLOCK, p->player_dir = 'E');
			if (map[i][j] == 'W')
				return (p->player_x = j*BLOCK, p->player_y = i*BLOCK, p->player_dir = 'W');
			j++;
		}
		i++;
	}
	return (1);
}

int	sv_textures(t_master *master)
{
	int i;

	i = 0;
	while (i < 4)
	{
		master->textures->t_array[i].img = mlx_xpm_file_to_image(master->mlx, master->textures->t_strings[i], &master->textures->t_array[i].width, &master->textures->t_array[i].height);
		if (!master->textures->t_array[i].img)
			return (ft_putstr_fd("test", 2), 1);
		master->textures->t_array[i].adress = mlx_get_data_addr(master->textures->t_array[i].img, &master->textures->t_array[i].bpp, &master->textures->t_array[i].size_line, &master->textures->t_array[i].endian);
		if (!master->textures->t_array[i].adress)
			return (ft_putstr_fd("test", 2), 1);
		i++;
	}
	return (0);
}

void	check_and_store_map(int fd, t_master *master)
{
	if (sv_file(fd, master))
		clean_n_exit(&master, fd);
	if (extract_textures(master))
		clean_n_exit(&master, fd);
	if (parse_textures(master->textures))
		clean_n_exit(&master, fd);
	if (map_extractor (master))
		clean_n_exit(&master, fd);
	if (sv_textures(master))
		clean_n_exit(&master, fd);
	sv_player_orientation(master->map->map, master->player);
}
