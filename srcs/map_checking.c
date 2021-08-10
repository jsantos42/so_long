#include "../include/main.h"

/*
**	Checks if the map is valid. A valid map must:
**	- be rectangular.
**	- be composed of only 5 possible characters: 0, 1, C, E and P.
**	- be closed/surrounded by walls (1).
**	- have at least one exit (E), one collectible (C), and one starting position
**	(P). The rest should be empty space (0).
*/

int	check_map_criteria(t_matrix *map)
{
	int	char_0;
	int	char_1;
	int	char_c;
	int	char_e;
	int	char_p;

	char_0 = find_char_in_map(map, '0');
	char_1 = find_char_in_map(map, '1');
	char_c = find_char_in_map(map, 'C');
	char_e = find_char_in_map(map, 'E');
	char_p = find_char_in_map(map, 'P');
	if (char_0 + char_1 + char_c + char_e + char_p != map->lines * map->columns
		|| char_c < 1 || char_e < 1 || char_p < 1)
		return (1);
	if (check_map_walls(map))
		return (1);
	return (0);
}


int	find_char_in_map(t_matrix *map, char letter)
{
	int	char_count;
	int	line;
	int	column;

	char_count = 0;
	line = 0;
	while (line < map->lines)
	{
		column = 0;
		while (map->matrix[line][column] != '\0')
		{
			if (map->matrix[line][column] == letter)
				char_count++;
			column++;
		}
		line++;
	}
	return (char_count);
}


int	check_map_walls(t_matrix *map)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	while (column < map->columns)
	{
		if (map->matrix[0][column] != '1'
			|| map->matrix[map->lines - 1][column] != '1')
			return (1);
		column++;
	}
	while (line < map->lines)
	{
		if (map->matrix[line][0] != '1'
			|| map->matrix[line][map->columns - 1] != '1')
			return (1);
		line++;
	}
	return (0);
}
