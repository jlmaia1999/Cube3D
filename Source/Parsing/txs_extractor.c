#include "parsing.h"

int	ft_atoi_rgb(const char *nptr)
{
	unsigned int	i;
	unsigned int	sign;
	int				result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	if (nptr[i])
		return (-1);
	return (result * sign);
}

int rgb_to_hex(char **rgb)
{
	int r;
	int g;
	int b;

	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (-1);
	r = ft_atoi_rgb(rgb[0]);
	g = ft_atoi_rgb(rgb[1]);
	b = ft_atoi_rgb(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}

int	sv_hex(char *texture, int *dir)
{
	int i;
	char **rgb;

	i = 0;
	while (texture[i] != ' ')
		i++;
	if (!texture[i])
		return (0);
	while (texture[i] == ' ')
		i++;
	if (!texture[i])
		return (0);
	rgb = ft_split (&texture[i], ',');
	*dir = rgb_to_hex(rgb);
	if (*dir == -1)
		return (1);
	free_array (rgb);
	return (0);
}

void	sv_texture(char *texture, char **dir)
{
	int i;

	i = 0;
	while (texture[i] != ' ')
		i++;
	if (!texture[i])
		return ;
	while (texture[i] == ' ')
		i++;
	if (!texture[i])
		return ;
	*dir = ft_substr (texture, i, ft_strlen(texture));
	return ;
}

int	extract_textures(t_master *master)
{
	int i;

	i = 0;
	while (master->map->file[i])
	{
		if (master->map->file[i][0] == 'N' && master->map->file[i][1] == 'O')
			sv_texture(master->map->file[i], &master->textures->n_texture);
		if (master->map->file[i][0] == 'S' && master->map->file[i][1] == 'O')
			sv_texture(master->map->file[i], &master->textures->s_texture);
		if (master->map->file[i][0] == 'W' && master->map->file[i][1] == 'E')
			sv_texture(master->map->file[i], &master->textures->w_texture);
		if (master->map->file[i][0] == 'E' && master->map->file[i][1] == 'A')
			sv_texture(master->map->file[i], &master->textures->e_texture);
		if (master->map->file[i][0] == 'F')
			sv_hex(master->map->file[i], &master->textures->floor_hex);
		if (master->map->file[i][0] == 'C')
			sv_hex(master->map->file[i], &master->textures->ceiling_hex);
		i++;
	}
	if (!master->textures->n_texture || !master->textures->s_texture || !master\
->textures->e_texture || !master->textures->w_texture || master->textures->\
ceiling_hex == -2 || master->textures->floor_hex == -2)
		return (ft_putstr_fd (ERR_TXS_MISS, 2), 1);
	else if (master->textures->ceiling_hex == -1 || master->textures->floor_hex == -1)
		return (ft_putstr_fd (ERR_RGB, 2), 1);
	return (0);
}

