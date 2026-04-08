#include "../../Includes/parsing.h"

void	free_array(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	error_exit(char *error)
{
	ft_putstr_fd (error, 2);
	exit (1);
}

void	clean_n_exit(t_master **master, int fd)
{
	if ((*master)->map->file)
		free_array((*master)->map->file);
	if ((*master)->map->map)
		free_array((*master)->map->map);
	free ((*master)->map);
	if ((*master)->textures->e_texture)
		free((*master)->textures->e_texture);
	if ((*master)->textures->n_texture)
		free((*master)->textures->n_texture);
	if ((*master)->textures->s_texture)
		free((*master)->textures->s_texture);
	if ((*master)->textures->w_texture)
		free((*master)->textures->w_texture);
	free ((*master)->textures);
	if ((*master)->player)
		free ((*master)->player);
	if ((*master)->win)
		mlx_destroy_window((*master)->mlx, (*master)->win);
	if ((*master)->mlx)
	{
		mlx_destroy_display((*master)->mlx);
		free ((*master)->mlx);
	}
	if (fd)
		close (fd);
	free (*master);
	exit (0);
}
