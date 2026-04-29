#include "../../Includes/parsing.h"


void	put_pixel(int x, int y, int color, t_image *image)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * image->size_line + x * image->bpp / 8;
	image->adress[index] = color & 0xFF;
	image->adress[index + 1] = (color >> 8) & 0xFF;
	image->adress[index + 2] = (color >> 16) * 0xFF;
}

void	clear_image(t_image *image)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, image);
			x++;
		}
		y++;
	}
}

void	draw_ray(t_master *master, float angle, int i)
{
	float	distance;
	float	true_distance;
	float	angle_diff;
	int		height;

	dda(master, angle);
	distance = master->ray->distance;
	angle_diff = angle - master->player->angle;
	if (angle_diff > PI)
		angle_diff -= PI * 2;
	else if (angle_diff < -PI)
		angle_diff += PI * 2;
	true_distance = distance * cos(angle_diff);
	if (true_distance < 0.001f)
		true_distance = 0.001f;
	height = HEIGHT / true_distance;
	draw_tex(master, i, (HEIGHT - height) / 2, (HEIGHT + height) / 2);
}

void	init_rays(t_master *master)
{
	int		i;
	float	start_x;
	float	fraction;

	i = 0;
	fraction = PI / 3 / WIDTH;
	start_x = master->player->angle - PI / 6;
	while (i < WIDTH)
	{
		draw_ray(master, start_x, i);
		start_x += fraction;
		i++;
	}
}


int	draw_loop(t_master *master)
{
	t_player *player;
	
	player = master->player;
	clear_image(master->image);
	move_player(player);
	draw_map(master);
	draw_square(player->player_x, player->player_y, 10, 0x00FF00, master);
	init_rays(master);
	mlx_put_image_to_window(master->mlx, master->win, master->image->img, 0, 0);
	return (0);
}
