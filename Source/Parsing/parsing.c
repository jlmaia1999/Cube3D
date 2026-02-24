#include "parsing.h"

int	map_ext_check(char *av)
{
	int	len;
	len = ft_strlen(av);

	if (len < 5 || ft_strnstr (av, ".cub", len) == NULL)
		return (1);
	if (ft_strncmp(&av[len - 4], ".cub", 4) || av[len - 5] == '/')
		return (1);
	return (0);
}
