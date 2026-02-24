#include "parsing.h"

void	error_exit(char *error)
{
	ft_putstr_fd (error, 2);
	exit (1);
}