#include "../../Includes/parsing.h"


void	put_pixel(int x, int y, int color, t_image *image)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * image->size_line + x * image->bpp / 8;
	image->data[index] = color & 0xFF;
	image->data[index + 1] = (color >> 8) & 0xFF;
	image->data[index + 2] = (color >> 16) * 0xFF;
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

int	draw_loop(t_master *master)
{
	t_player *player;
	
	player = master->player;
	clear_image(master->image);
	move_player(player);
	draw_map(master);
	draw_square(player->player_x, player->player_y, 10, 0x00FF00, master);
	draw_ray(master);
	mlx_put_image_to_window(master->mlx, master->win, master->image->img, 0, 0);
	return (0);
}
