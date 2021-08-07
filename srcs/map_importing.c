#include "../include/main.h"

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

char	**import_map(char *str)
{
	int		fd;
	size_t 	line_count;
	size_t	line_length;
	char 	**map;
	t_list	*line_list;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_management(ERROR_READING_FILE);
	line_list = map_lines_to_linked_list(fd, &line_count, &line_length);
	map = linked_list_to_matrix(line_list, line_count);
	if (check_map_criteria(map, line_count, line_length))
		free_matrix_and_exit(INVALID_MAP, map, line_count);
	return (map);
}

/*
**	Parses through the file and saves every read line to a new node on a linked
**	list. Before doing so, it does check if the size of every line is the same,
**	because the program requires a rectangular map.
*/

t_list	*map_lines_to_linked_list(int fd, size_t *line_count, size_t *line_length)
{
	char	*line;
	t_list	*temp;
	t_list	*line_list;

	*line_count = 0;
	*line_length = 0;
	while (get_next_line(fd, &line))
	{
		if (!line)
			free_list_and_exit(FAILED_MALLOC, line_list);
		if (!*line_length)
			*line_length = ft_strlen(line);
		else if (*line_length != ft_strlen(line))
			free_list_and_exit(INVALID_MAP, line_list);
		temp = ft_lstnew(line);
		if (!temp)
			free_list_and_exit(FAILED_MALLOC, line_list);
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

char	**linked_list_to_matrix(t_list *line_list, size_t line_count)
{
	t_list	*temp;
	size_t	i;
	char	**map;

	map = malloc(sizeof(char*) * line_count);
	if (!map)
		free_list_and_exit(FAILED_MALLOC, line_list);
	i= 0;
	while (i < line_count)
	{
		temp = line_list->next;
		map[i] = line_list->content;
		free(line_list);
		line_list = temp;
		i++;
	}
	return (map);
}
