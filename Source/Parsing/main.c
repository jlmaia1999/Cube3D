#include "../../Includes/parsing.h"

void	init_mlx(t_master **master)
{
	(*master)->mlx = mlx_init();
	if (!(*master)->mlx)
	{
		perror("Mlx_aloc Error: ");
		clean_n_exit(master, 0);
	}
	(*master)->win = mlx_new_window((*master)->mlx, WIDTH, HEIGHT, "cub3d");
	if (!(*master)->win)
	{
		perror("Mlx_win Error: ");
		clean_n_exit(master, 0);
	}
	(*master)->image->img = mlx_new_image((*master)->mlx, WIDTH, HEIGHT);
	(*master)->image->data = mlx_get_data_addr((*master)->image->img, &(*master)->image->bpp, &(*master)->image->size_line, &(*master)->image->endian);
	mlx_put_image_to_window((*master)->mlx, (*master)->win, (*master)->image->img, 0, 0);
}

void	master_init2(t_master **master)
{
	(*master)->textures = malloc (sizeof(t_textures));
	if (!(*master)->textures)
	{
		free((*master)->map);
		free((*master)->image);
		free ((*master));
		perror("Mem_aloc Error: ");
		exit (1);
	}
	ft_memset ((*master)->textures, 0, sizeof(t_textures));
	(*master)->textures->ceiling_hex = -2;
	(*master)->textures->floor_hex = -2;
	(*master)->player = malloc (sizeof(t_player));
	if (!(*master)->player)
	{
		free((*master)->map);
		free((*master)->textures);
		free((*master)->image);
		free ((*master));
		perror("Mem_aloc Error: ");
		exit (1);
	}
	ft_memset ((*master)->player, 0, sizeof(t_player));
	init_mlx(master);
}

void	master_init(t_master **master)
{
	*master = ft_calloc (sizeof(t_master), 1);
	if (!*master)
	{
		perror("Mem_aloc Error: ");
		exit (1);
	}
	(*master)->map = ft_calloc (sizeof(t_map), 1);
	if (!(*master)->map)
	{
		free ((*master));
		perror("Mem_aloc Error: ");
		exit (1);
	}
	(*master)->image = ft_calloc(sizeof(t_textures), 1);
	if (!(*master)->image)
	{
		free((*master)->map);
		free ((*master));
		perror("Mem_aloc Error: ");
		exit (1);
	}
	(*master)->ray = calloc(sizeof(t_ray), 1);
	if (!(*master)->ray)
	{
		free((*master)->map);
		free((*master)->image);
		free ((*master));
		perror("Mem_aloc Error: ");
		exit (1);
	}
	master_init2(master);
}


int	parsing(int ac, char **av, t_master *master)
{
	int			fd;

	if (ac < 2)
		error_exit(ERR_NO_MAP);
	if (ac > 2)
		error_exit(ERR_ARGS);
	if (extension_checker(av[1], ".cub"))
		error_exit(ERR_MAP_EXT);
	if ((fd = open (av[1], O_RDONLY)) < 0)
		error_exit(ERR_FILE_OPEN);
	check_and_store_map(fd, master);
	close(fd);
	return (0);
}
