#include "../../Includes/parsing.h"

int	parse_textures(t_textures *texs)
{
	int fd;
	int i;

	i = 0;
	while (i < 4)
	{
		if (extension_checker(texs->t_strings[i], ".xpm"))
			return (ft_putstr_fd(ERR_TEX_EXT, 2), 1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if ((fd = open(texs->t_strings[i], O_RDONLY)) < 0)
			return (ft_putstr_fd(ERR_TEX_OPEN, 2), 1);
		close (fd);
		i++;
	}
	return (0);
}


