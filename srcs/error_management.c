#include "../include/main.h"

void	error_management(int error)
{
	ft_putstr_fd("Error\n", 1);
	if (error == ILLEGAL_INPUT)
		ft_putstr_fd("Wrong input. Please run ./so_long <path_to_file.ber>\n", 1);
	else if (error == FAILED_MALLOC)
		ft_putstr_fd("Memory allocation failed.\n", 1);
	else if (error == WRONG_EXTENSION)
	{
		ft_putstr_fd("The given map has not a .ber extension.\n", 1);
		ft_putstr_fd("Please provide the correct file.\n", 1);
	}
	else if (error == ERROR_READING_FILE)
		ft_putstr_fd("Couldn't read the given map file.\n", 1);
	else if (error == WRONG_MAP_SHAPE)
	{
		ft_putstr_fd("The given map is not rectangular.\n", 1);
		ft_putstr_fd("Please provide a valid map.\n", 1);
	}
	exit(error);
}