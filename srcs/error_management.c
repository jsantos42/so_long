#include "../include/main.h"

void	error_management(int error)
{
	if (error == 1)
		ft_putstr_fd("Wrong input. Please run ./so_long <path_to_file.ber>\n");
	exit(error);
}