#include "parsing.h"

void	master_init(t_master *master)
{
	
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
		error_exit(ERR_MAP_OPEN);
	master_init(master);
	close (fd);
	check_and_store_map(fd, master);
}
