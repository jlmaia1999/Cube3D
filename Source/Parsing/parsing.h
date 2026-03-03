
#ifndef PARSING_H
#define PARSING_H

# include "../../Resources/Libft/libft.h"
# include "../../Resources/Minilibx/mlx.h"
# include "../../Resources/Minilibx/mlx_int.h"
# include "../../Resources/ft_printf/ft_printf.h"

# define ERR_NO_MAP "Error\nNo map file provided\n"
# define ERR_ARGS "Error\nToo many arguments provided\n"
# define ERR_MAP_EXT "Error\nInvalid map file extension\n"
# define ERR_FILE_OPEN "Error\nUnable to open map file\n"
# define ERR_MAP_EMPTY "Error\nMap file is empty\n"
# define ERR_MAP_SHAPE "Error\nMap shape is invalid\n"
# define ERR_RGB "Error\nInvalid RGB values\n"
# define ERR_TXS_MISS "Error\nOne or more textures missing\n"
# define ERR_MAP_ELEM "Error\nMap has 1 or more invalid element/ is missing a starting orientation\n"
# define ERR_MAP_OPEN "Error\nThe Map must be surrounded by walls and spaces are not allowed inside!\n"



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
void	check_and_store_map(int fd, t_master *master);
int		sv_file(int fd, t_master *master);
int		extract_textures(t_master *master);
int		map_extractor(t_master *master);
int		map_parser(char **map);


#endif