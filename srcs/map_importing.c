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
//	size_t 	size;
	char 	**map;
	t_list	*line_list;
	t_list	*temp;
//	int 	line_counter;

	//new stack

	fd = open(*str, O_RDONLY); //create a condition here in case it fails
	while (get_next_line(fd, &line))
	{
		//check is the line is the same as length as the previous ones
		temp = ft_lstnew(line);
		if (!line_list)
			line_list = temp;
		else
			ft_lstadd_front(&line_list, temp);
	}
	// check how many nodes the list has, thats the number of rows
	//create a matrix with that number as the size of the malloc of the first value and
	//the ft_strlen (line) as the second number



}

