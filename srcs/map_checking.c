#include "../include/main.h"

/*
**	Checks if the map is valid. A valid map must:
**	- be rectangular.
**	- be composed of only 5 possible characters: 0, 1, C, E and P.
**	- be closed/surrounded by walls (1).
**	- have at least one exit (E), one collectible (C), and one starting position
**	(P). The rest should be empty space (0).
*/

int	check_map_criteria(char **map, size_t line_count, size_t line_length)
{
	size_t	char_0;
	size_t	char_1;
	size_t	char_c;
	size_t	char_e;
	size_t	char_p;

	char_0 = find_char_in_map(map, line_count, '0');
	char_1 = find_char_in_map(map, line_count, '1');
	char_c = find_char_in_map(map, line_count, 'C');
	char_e = find_char_in_map(map, line_count, 'E');
	char_p = find_char_in_map(map, line_count, 'P');
	if (char_0 + char_1 + char_c + char_e + char_p != line_count * line_length
		|| char_c < 1 || char_e < 1 || char_p < 1)
		return (1);
	if (check_map_walls(map, line_count, line_length))
		return (1);
	return (0);
}


int	find_char_in_map(char **map, size_t line_count, char letter)
{
	int 	char_count;
	size_t	column;
	size_t	line;

	char_count = 0;
	column = 0;
	line = 0;
	while (line < line_count)
	{
		column = 0;
		while (map[line][column] != '\0')
		{
			if (map[line][column] == letter)
				char_count++;
			column++;
		}
		line++;
	}
	return (char_count);
}


int	check_map_walls(char **map, size_t line_count, size_t line_length)
{
	size_t	line;
	size_t	column;

	line = 0;
	column = 0;
	while (column < line_length)
	{
		if (map[0][column] != '1' || map[line_count - 1][column] != '1')
			return (1);
		column++;
	}
	while (line < line_count)
	{
		if (map[line][0] != '1' || map[line][line_length - 1] != '1')
			return (1);
		line++;
	}
	return (0);
}
