#ifndef CUBE3D_EXEC_H
# define CUBE3D_EXEC_H

# include "../lib/libft/libft.h"
// # include "../lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

enum e_textures
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_vector
{
	double	camera_rotation;
	double	vector_x;
	double	vector_y;
	int		map_x;
	int		map_y;
	
}	t_vector;


#endif