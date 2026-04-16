#include "../../Includes/parsing.h"

void	init_ray(t_ray *ray)
{
	ft_memset(ray, 0, sizeof(ray));
}


bool touch(float px, float py, t_master *master)
{
    int x = px / BLOCK;
    int y = py / BLOCK;
    if(master->map->map[y][x] == '1')
        return true;
    return false;
}

void	detect_wall(t_master *master, float *ray)
{
	int	i;
	float	side_dist_x;
	// float	side_dist_y;

	(void)ray;
	side_dist_x = ((((int)master->player->player_x) >> 6 ) << 6) - 0.0001;
	i = 0;
	// while (master->map->map[i])
	// {
	// 	if ()
	// }
}

void	draw_ray(t_master *master)
{
	float	ray[2];
	float	cos_angle;
	float	sin_angle;

	ray[0] = master->player->player_x;
	ray[1] = master->player->player_y;
	cos_angle = cos(master->player->angle);
	sin_angle = sin(master->player->angle);
	while(!touch(ray[0], ray[1], master))
	{
		put_pixel(ray[0], ray[1], 0xFF0000, master->image);
		ray[0] += cos_angle;
		ray[1] += sin_angle;
	}
	// return(ray);
}
