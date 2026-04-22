#ifndef PARSING_H
#define PARSING_H

# include "../Resources/Libft/libft.h"
# include "../Resources/Minilibx/mlx.h"
# include "../Resources/Minilibx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "stdbool.h"
# include "math.h"
# include "structs.h"

# define WIDTH 1920
# define HEIGHT 1080

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359

# define BLOCK 64

# define ERR_NO_MAP "Error\nNo map file provided\n"
# define ERR_NO_MAP_INFILE "Error\nFile provided has no map\n"
# define ERR_ARGS "Error\nToo many arguments provided\n"
# define ERR_MAP_EXT "Error\nInvalid map file extension\n"
# define ERR_FILE_OPEN "Error\nUnable to open map file\n"
# define ERR_MAP_EMPTY "Error\nMap file is empty\n"
# define ERR_MAP_SHAPE "Error\nMap shape is invalid or parameters stated incorrectly\n"
# define ERR_RGB "Error\nInvalid RGB values\n"
# define ERR_RGB_DUP "Error\nDuplicate RGB reference encountered\n"
# define ERR_TXS_MISS "Error\nOne or more textures missing\n"
# define ERR_TXS_DUP "Error\nDuplicate texture reference encountered\n"
# define ERR_MAP_ELEM "Error\nMap has 1 or more invalid element/ is missing a starting orientation\n"
# define ERR_MAP_OPEN "Error\nThe Map must be surrounded by walls and spaces are not allowed inside!\n"
# define ERR_TEX_EXT "Error\nInvalid texture file extension\n"
# define ERR_TEX_OPEN "Error\nUnable to open texture file\n"



void	error_exit(char *error);
int		extension_checker(char *av, char *ext);
void	clean_n_exit(t_master **master, int fd);
void	free_array(char **s);
void	check_and_store_map(int fd, t_master *master);
int		sv_file(int fd, t_master *master);
int		extract_textures(t_master *master);
int		map_extractor(t_master *master);
int		map_parser(char **map);
int		parse_textures(t_textures *texs);
int		sv_player_orientation(char **map, t_player *p);
int		parsing(int ac, char **av, t_master *master);
void	master_init(t_master **master);

void	move_player(t_player *player);
int		key_release(int keycode, t_player *player);
int		key_press(int keycode, t_player *player);
int		draw_loop(t_master *master);
void	draw_map(t_master *master);
void	draw_square(int x, int y, int size, int color, t_master *master);
void	put_pixel(int x, int y, int color, t_image *image);
void	init_player(t_player *player);
void	draw_ray(t_master *master, float angle);
void	dda(t_master *master, float angle);




#endif