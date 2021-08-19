#include "../include/error_and_free.h"

static void	free_map(t_matrix *map);
static void	free_textures(t_vars *vars);

/*
**	Prints the correct error message in the CLI before exiting the program.
*/

void	error_management(int error)
{
	ft_putstr_fd("Error\n", 1);
	if (error == ILLEGAL_INPUT)
		ft_putstr_fd("Wrong input. Run ./so_long <path_to_file.ber>\n", 1);
	else if (error == FAILED_MALLOC)
		ft_putstr_fd("Memory allocation failed.\n", 1);
	else if (error == WRONG_EXTENSION)
		ft_putstr_fd("The given map has not a .ber extension.\n", 1);
	else if (error == ERROR_READING_MAP_FILE)
		ft_putstr_fd("Couldn't read the given map file.\n", 1);
	else if (error == INVALID_MAP)
	{
		ft_putstr_fd("The given map is not valid. A valid map must:\n", 1);
		ft_putstr_fd("- be rectangular.\n", 1);
		ft_putstr_fd("- have only the following chars: 0, 1, C, E and P.\n", 1);
		ft_putstr_fd("- be closed/surrounded by walls (1).\n", 1);
		ft_putstr_fd("- have 1 starting position (P), 1 exit (E), and >=\n", 1);
		ft_putstr_fd(" 1 collectible (C). The rest is empty space (0).\n", 1);
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
	if (vars)
	{
		if (vars->map)
			free_map(vars->map);
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

static void	free_map(t_matrix *map)
{
	int	line_i;

	{
		if (map->matrix)
		{
			line_i = 0;
			while (line_i < map->lines)
				free(map->matrix[line_i++]);
			free(map->matrix);
		}
		free(map);
	}
}
/*
**	Frees the textures. Gets called before terminating the program.
*/

static void	free_textures(t_vars *vars)
{
	ft_free_matrix(vars->wall, HEIGHT);
	ft_free_matrix(vars->free_space, HEIGHT);
	ft_free_matrix(vars->exit, HEIGHT);
	ft_free_matrix(vars->enemy, HEIGHT);
	ft_free_matrix(vars->collectible, HEIGHT);
	ft_free_matrix(vars->player_right, HEIGHT);
	ft_free_matrix(vars->player_left, HEIGHT);
	ft_free_matrix(vars->end, HEIGHT);
}
