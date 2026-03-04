#include "parsing.h"

void	master_init(t_master **master)
{
	*master = malloc (sizeof(t_master));
	if (!*master)
	{
		perror("Mem_aloc Error: ");
		exit (1);
	}
	(*master)->map = malloc (sizeof(t_map));
	if (!(*master)->map)
	{
		free ((*master));
		perror("Mem_aloc Error: ");
		exit (1);
	}
	(*master)->map = ft_memset ((*master)->map, 0, sizeof (t_map));
	(*master)->textures = malloc (sizeof(t_textures));
	if (!(*master)->textures)
	{
		free((*master)->map);
		free ((*master));
		perror("Mem_aloc Error: ");
		exit (1);
	}
	ft_memset ((*master)->textures, 0, sizeof(t_textures));
	(*master)->textures->ceiling_hex = -2;
	(*master)->textures->floor_hex = -2;
}

int	main(int ac, char **av)
{
	int			fd;
	t_master	*master;

	if (ac < 2)
		error_exit(ERR_NO_MAP);
	if (ac > 2)
		error_exit(ERR_ARGS);
	if (map_ext_check(av[1]))
		error_exit(ERR_MAP_EXT);
	if ((fd = open (av[1], O_RDONLY)) < 0)
		error_exit(ERR_FILE_OPEN);
	master_init(&master);
	check_and_store_map(fd, master);
	close (fd);
}
