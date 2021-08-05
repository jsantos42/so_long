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

char	**import_map(char **str)
{
	int		fd;
	char	*line;
	size_t 	line_counter;
	size_t	line_length;
	char 	**map;
	t_list	*line_list;
	t_list	*temp;


	fd = open(*str, O_RDONLY);
	if (fd < 0)
		error_management(ERROR_READING_FILE);
	line_counter = 0;
//this could go into a separate function
	while (get_next_line(fd, &line))
	{
		if (!line_length)
			line_length = ft_strlen(line);
		else
			if (line_length != ft_strlen(line))
				error_management(WRONG_MAP_SHAPE);
		temp = ft_lstnew(line); //I think its constantly changing the line value
		//on different nodes, because its always the same pointer. Maybe creating a
		//new temp string for each would help
		if (!line_list)
			line_list = temp;
		else
			ft_lstadd_front(&line_list, temp);
		line_counter++;
	}

	map = malloc(sizeof(char*) * line_counter);

//this could go into a separate function
	t_list	*temp2;
	size_t	i = 0;
	while (i < line_counter)
	{
		temp2 = line_list->next;
		map[i] = malloc(sizeof(char) * (line_length + 1));
		map[i] = line_list->content;
		free(line_list);
		line_list = temp;
		i++;
	}

}

