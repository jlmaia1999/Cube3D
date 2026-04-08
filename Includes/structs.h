#ifndef STRUCTS_H
# define STRUCTS_H

# include "../Resources/Libft/libft.h"
# include "../Resources/Minilibx/mlx.h"
# include "../Resources/Minilibx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "stdbool.h"
# include "math.h"
# include "exec.h"


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

typedef struct s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}	t_image;

typedef struct s_ray
{
	double	camera_rotation;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	double	wall_hit;
	int		side;
}	t_ray;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	char	player_dir;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_master
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_textures	*textures;
	t_player	*player;
}	t_master;

#endif