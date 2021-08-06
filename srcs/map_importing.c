#include "../include/main.h"

int		check_map_extension(char *str)
{
	size_t	size;
	char	*extension;
	int 	output;

	size = ft_strlen(str);
	extension = ft_substr(str, size - 5, 4);
	output = ft_strncmp(extension, ".ber", 4);
	free(extension);
	return (output);
}

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
	return (map);
}


t_list	*map_lines_to_linked_list(int fd, size_t *line_count, size_t *line_length)
{
	char	*line;
	t_list	*temp;
	t_list	*line_list;

	line_count = 0;
	while (get_next_line(fd, &line))
	{
		if (!*line_length)
			*line_length = ft_strlen(line);
		else
			if (*line_length != ft_strlen(line))
				error_management(WRONG_MAP_SHAPE);
		temp = ft_lstnew(line);
		//I think its constantly changing the line value
		//on different nodes, because its always the same pointer. Maybe creating a
		//new temp string for each would help
		if (!line_list)
			line_list = temp;
		else
			ft_lstadd_back(&line_list, temp);
		(*line_count)++;
	}
	return (line_list);
}


char	**linked_list_to_matrix(t_list *line_list, size_t line_count)
{
	t_list	*temp;
	size_t	i;
	char	**map;

	map = malloc(sizeof(char*) * line_count);
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

