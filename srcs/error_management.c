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
	else if (error == INVALID_MAP)
	{
		ft_putstr_fd("The given map is not valid. A valid map must:\n", 1);
		ft_putstr_fd("- be rectangular.\n", 1);
		ft_putstr_fd("- be composed of only 5 possible characters: 0, 1,", 1);
		ft_putstr_fd(" C, E and P.\n", 1);
		ft_putstr_fd("- be closed/surrounded by walls (1).\n", 1);
		ft_putstr_fd("- have at least one exit (E), one collectible (C),", 1);
		ft_putstr_fd(" and one starting position (P). The rest should", 1);
		ft_putstr_fd(" be empty space (0).\n", 1);
	}
	exit(error);
}


/*
**	This static function deletes and frees the existing nodes on the linked list
**	and calls error_management to throw an error message before exiting.
*/

void	free_list_and_exit(int error, t_list *line_list)
{
	ft_lstclear(&line_list, erase_str);
	error_management(error);
}

void	free_matrix_and_exit(int error, char **map, size_t lines)
{
	size_t	line_i;

	line_i = 0;
	while (line_i <  lines)
		free(map[line_i++]);
	free(map);
	error_management(error);
}
