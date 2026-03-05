#include "parsing.h"

int	parse_textures(t_textures *texs)
{
	int fd;

	if (extension_checker(texs->n_texture, ".xpm"))
		return (ft_putstr_fd(ERR_TEX_EXT, 2), 1);
	if (extension_checker(texs->s_texture, ".xpm"))
		return (ft_putstr_fd(ERR_TEX_EXT, 2), 1);
	if (extension_checker(texs->e_texture, ".xpm"))
		return (ft_putstr_fd(ERR_TEX_EXT, 2), 1);
	if (extension_checker(texs->w_texture, ".xpm"))
		return (ft_putstr_fd(ERR_TEX_EXT, 2), 1);
	if ((fd = open(texs->n_texture, O_RDONLY)) < 0)
		return (ft_putstr_fd(ERR_TEX_OPEN, 2), 1);
	close (fd);
	if ((fd = open(texs->s_texture, O_RDONLY)) < 0)
		return (ft_putstr_fd(ERR_TEX_OPEN, 2), 1);
	close (fd);
	if ((fd = open(texs->e_texture, O_RDONLY)) < 0)
		return (ft_putstr_fd(ERR_TEX_OPEN, 2), 1);
	close (fd);
	if ((fd = open(texs->w_texture, O_RDONLY)) < 0)
		return (ft_putstr_fd(ERR_TEX_OPEN, 2), 1);
	close (fd);
	return (0);
}


