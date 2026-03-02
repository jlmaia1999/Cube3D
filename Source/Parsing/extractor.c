#include "parsing.h"

int rgb_to_hex(char **rgb)
{
    int r;
    int g;
    int b;

    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
        return (-1);
    
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (-1);
    
    return (r << 16 | g << 8 | b);
}

void    sv_hex(char *texture, int *dir)
{
    int i;
    char **rgb;

    i = 0;
    while (texture[i] != ' ')
        i++;
    if (!texture[i])
        return ;
    while (texture[i] == ' ')
        i++;
    if (!texture[i])
        return ;
    rgb = ft_split (&texture[i], ',');
    *dir = rgb_to_hex(rgb);
    if (*dir == -1)
    {
        ft_putstr_fd ()
        return ;
    }
    free_array (rgb);
    return ;
}

void    sv_texture(char *texture, char **dir)
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

void	extract_textures(t_master *master)
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
}

