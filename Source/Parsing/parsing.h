
#ifndef PARSING_H
#define PARSING_H

# include "../../Resources/Libft/libft.h"
# include "../../Resources/Minilibx/mlx.h"
# include "../../Resources/Minilibx/mlx_int.h"
# include "../../Resources/ft_printf/ft_printf.h"

# define ERR_NO_MAP "Error\nNo map file provided\n"
# define ERR_ARGS "Error\nToo many arguments provided\n"
# define ERR_MAP_EXT "Error\nInvalid map file extension\n"
# define ERR_MAP_OPEN "Error\nUnable to open map file\n"
# define ERR_MAP_EMPTY "Error\nMap file is empty\n"
# define ERR_MAP_SHAPE "Error\nMap shape is invalid\n"


typedef struct s_map
{
	char **file;
	char **map;
}	t_map;

typedef struct s_textures
{
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	int		floor_hex;
	int		ceiling_hex;
}	t_textures;

typedef struct s_master
{
	t_map		*map;
	t_textures	*textures;
}	t_master;

void	error_exit(char *error);
int		map_ext_check(char *av);
void	clean_n_exit(t_master **master);
void	free_array(char **s);
void		check_and_store_map(int fd, t_master *master);
int	sv_file(int fd, t_master *master);
void	extract_textures(t_master *master);


#endif