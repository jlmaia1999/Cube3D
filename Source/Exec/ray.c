#include "../../Includes/parsing.h"

void	init_ray(t_master *master, float angle)
{
	t_ray *ray;

	ray = master->ray;
	ray->ray_dir_x = cos(angle);
	ray->ray_dir_y = sin(angle);
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

void	get_side_dist(t_master *master, float px, float py, int pos[2])
{
	t_ray *ray;

	ray = master->ray;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (px - pos[0]) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (pos[0] + 1.0f - px) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (py - pos[1]) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (pos[1] + 1.0f - py) * ray->delta_dist_y;
	}
}


bool touch(float px, float py, t_master *master)
{
    int x = px / BLOCK;
    int y = py / BLOCK;
    if(master->map->map[y][x] == '1')
        return true;
    return false;
}

void	raycasting(t_master *master, int pos[2])
{
	t_ray	*ray;

	ray = master->ray;
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			pos[0] += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			pos[1] += ray->step_y;
			ray->side = 0;
		}
		if (touch(pos[0], pos[1], master))
			break ;
	}
}

void	dda(t_master *master, float angle)
{
	float	px;
	float	py;
	int		pos[2];

	px = master->player->player_x / BLOCK;
	py = master->player->player_y / BLOCK;
	pos[0] = (int)px;
	pos[1] = (int)py;
	init_ray(master, angle);
	get_side_dist(master, px, py, pos);
	raycasting(master, pos);
	if (master->ray->side == 0)
		master->ray->distance = (pos[0] - px + (1 - master->ray->step_x) * 0.5f) / master->ray->ray_dir_x;
	else
		master->ray->distance = (pos[1] - py + (1 - master->ray->step_y) * 0.5f) / master->ray->ray_dir_y;
}
