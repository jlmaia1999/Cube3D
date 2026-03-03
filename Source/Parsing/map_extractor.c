#include "parsing.h"

int	sv_map(int i, t_master *master)
{
	int j;

	j = 0;
	while (master->map->file[i + j])
		j++;
	master->map->map = ft_calloc (sizeof(char *), (j + 2));
	if (!master->map->map)
		return (ft_putstr_fd ("ERROR\nMalloc error\n", 2), 1);
	j = 0;
	while (master->map->file[i + j])
	{
		master->map->map[j] = ft_strdup(master->map->file[i + j]);
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
