
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


void	error_exit(char *error);
int		map_ext_check(char *av);

#endif