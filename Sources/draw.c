#include "cube3D_exec.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) * 0xFF;
}

void	clear_image(t_game *game)
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
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}

void	draw_loop(t_game *game)
{
	t_player *player;
	
	player = &game->player;
	move_player(player);
	clear_image(game);

}