#include "../include/1_error_management.h"

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
	else if (error == ERROR_READING_MAP_FILE)
		ft_putstr_fd("Couldn't read the given map file.\n", 1);
	else if (error == INVALID_MAP)
	{
		ft_putstr_fd("The given map is not valid. A valid map must:\n", 1);
		ft_putstr_fd("- be rectangular.\n", 1);
		ft_putstr_fd("- have only the following chars: 0, 1, C, E and P.\n", 1);
		ft_putstr_fd("- be closed/surrounded by walls (1).\n", 1);
		ft_putstr_fd("- have at least one exit (E), one collectible (C),", 1);
		ft_putstr_fd(" and one starting position (P). The rest should", 1);
		ft_putstr_fd(" be empty space (0).\n", 1);
	}
	else if (error == ERROR_READING_IMAGE_FILE)
		ft_putstr_fd("Couldn't read one or more of the images files.\n", 1);
	else if (error == NO_CONNECTION)
		ft_putstr_fd("Couldn't establish a connection to a window.\n", 1);
	else if (error == NO_WINDOW)
		ft_putstr_fd("Couldn't create a window.\n", 1);
	exit(error);
}


/*
**	Deletes and frees the existing nodes on the linked list and returns NULL, so
**	that the caller function can throw an error.
*/

void	*free_list(t_list *line_list)
{
	ft_lstclear(&line_list, ft_str_eraser);
	return (NULL);
}

/*
**	Frees the given matrix and calls error_management to throw an error message
**	before exiting.
*/

void	free_vars_and_exit(int error, t_vars *vars)
{
	int	line_i;

	if (vars)
	{
		if (vars->map)
		{
			line_i = 0;
			while (line_i < vars->map->lines)
				free(vars->map->matrix[line_i++]);
			free(vars->map->matrix);
			free(vars->map);
		}
		free_textures(vars);
		if (vars->img)
			mlx_destroy_image(vars->connection, vars->img);
		if (vars->window)
			mlx_destroy_window(vars->connection, vars->window);
		free(vars);
	}
	if (error)
		error_management(error);
	else
		exit(0);
}
