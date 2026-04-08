#include "../Includes/structs.h"
#include "../Includes/parsing.h"

int	main(int argc, char **argv)
{
	t_master *master;

	master_init(&master);
	parsing(argc, argv, master);
	clean_n_exit(&master, 0);
}