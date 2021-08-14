#include "../include/map_importing.h"

/*
**	Checks if the file passed as an argument has a .ber extension. If so,
**	returns 0; otherwise returns an integer greater than or less than 0, which
**	corresponds to the difference of characters of the two strings compared.
*/

int		check_map_extension(char *str)
{
	size_t	size;
	char	*extension;
	int 	output;

	size = ft_strlen(str);
	extension = ft_substr(str, size - 4, 4);
	if (!extension)
		error_management(FAILED_MALLOC);
	output = ft_strncmp(extension, ".ber", 4);
	free(extension);
	return (output);
}

/*
**	Imports the map from the file passed as an argument to a matrix. As it does
**	not know the number of lines in the map when it starts reading it, it cannot
**	allocate memory to the first array of the matrix. Therefore, and in order to
**	avoid reading the file more than once, it saves each read line to a node in
**	a linked list. After finishing reading the file, it can allocate memory to
**	the matrix (map) and move the lines' content to the it.
*/

t_vars	*import_map(char *str)
{
	int			fd;
	t_list		*line_list;
	t_vars		*vars;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_management(ERROR_READING_MAP_FILE);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		free_vars_and_exit(FAILED_MALLOC, vars);
	vars->map = malloc(sizeof(t_matrix));
	if (!vars->map)
		free_vars_and_exit(FAILED_MALLOC, vars);
	line_list = map_lines_to_linked_list(fd, &vars->map->lines, &vars->map->columns, vars);
	if (!line_list)
		free_vars_and_exit(FAILED_MALLOC, vars);
	vars->map->matrix = linked_list_to_matrix(line_list, vars->map->lines, vars);
	if (check_map_criteria(vars->map))
		free_vars_and_exit(INVALID_MAP, vars);
	vars->map->moves_count = 0;
	vars->map->end_of_game = 0;
	vars->map->text_color = 0xFFFFFF;
	vars->map->text_x = IMG_WIDTH * 1;
	vars->map->text_y = IMG_HEIGHT * 0.57;
	get_player_xy_and_collectible_count(vars->map);
	if (BONUS)
		place_enemies(vars->map);
	return (vars);
}

/*
**	Parses through the file and saves every read line to a new node on a linked
**	list. Before doing so, it does check if the size of every line is the same,
**	because the program requires a rectangular map.
*/

t_list	*map_lines_to_linked_list(int fd, int *line_count, int *line_length, t_vars *vars)
{
	char	*line;
	t_list	*temp;
	t_list	*line_list;

	*line_count = 0;
	*line_length = 0;
	line_list = NULL;
	while (get_next_line(fd, &line))
	{
		if (!line)
			return (free_list(line_list));
		if (!*line_length)
			*line_length = ft_strlen(line);
		else if (*line_length != (int)ft_strlen(line))
		{
			free_list(line_list);
			free_vars_and_exit(INVALID_MAP, vars);
		}
		temp = ft_lstnew(line);
		if (!temp)
			return (free_list(line_list));
		if (!line_list)
			line_list = temp;
		else
			ft_lstadd_back(&line_list, temp);
		(*line_count)++;
	}
	return (line_list);
}

/*
**	Moves the lines' content to a matrix and frees the linked list.
*/

char	**linked_list_to_matrix(t_list *line_list, size_t line_count, t_vars *vars)
{
	t_list	*temp;
	size_t	i;
	char	**matrix;

	matrix = malloc(sizeof(char*) * line_count);
	if (!matrix)
	{
		free_list(line_list);
		free_vars_and_exit(FAILED_MALLOC, vars);
	}
	i= 0;
	while (i < line_count)
	{
		temp = line_list->next;
		matrix[i] = line_list->content;
		free(line_list);
		line_list = temp;
		i++;
	}
	return (matrix);
}

void	get_player_xy_and_collectible_count(t_matrix *map)
{
	int x;
	int y;

	map->collectible_count = 0;
	y = 0;
	while (y < map->lines)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->matrix[y][x] == 'P')
			{
				map->player_coord_x = x;
				map->player_coord_y = y;
			}
			else if (map->matrix[y][x] == 'C')
				map->collectible_count++;
			x++;
		}
		y++;
	}
}
