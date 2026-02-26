#ifndef CUBE3D_EXEC_H
# define CUBE3D_EXEC_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

enum e_textures
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_img
{
	void	*img;
}	t_img;

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

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;


typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_ray		ray;
	t_map		map;
}	t_game;

void	free_args(char **args);

#endif