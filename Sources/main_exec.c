#include "cube3D_exec.h"

void	init_map(t_game *game)
{
	int	i;

	i = 0;
	game->map.height = 8;
	game->map.width = 8;
	game->map.map = calloc(game->map.height, sizeof(char *));
	if (!game->map.map)
	{
		printf("Erro");
		return ;
	}
	while (i < game->map.height)
	{
		game->map.map[i] = calloc (game->map.width, sizeof(char));
		if (!game->map.map[i])
		{
			printf("Erro");
			return ;
		}
		i++;
	}
	game->map.map[2][2] = '1';
	game->map.map[2][3] = '1';
	game->map.map[5][5] = 'P';
}

void	draw_map(t_game *game)
{

}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * 64, game->map.height * 64, "Cub3d");
	draw_map(game);
}

int main()
{
	t_game *game;

	game = malloc(sizeof(t_game));
	init_map(game);
	init_window(game);
	mlx_loop(game->mlx);
}