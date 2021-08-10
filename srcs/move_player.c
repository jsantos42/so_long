#include "../include/main.h"

void	move_player(char *current_position, char *new_position)
{
	char	temp;

	if (*new_position == '1')
		return;
	if (*new_position == 'C')
		*new_position = '0';
	else if (*new_position == 'E')
	{
		*current_position = '0';
		return;
	}


	temp = *new_position;
	*new_position = *current_position;
	*current_position = temp;
}


//char	*get_player_position(t_matrix *map)
//{
//	int	line;
//	int	column;
//
//	line = 0;
//	while (line < map->lines)
//	{
//		column = 0;
//		while (map->matrix[line][column] != '\0')
//		{
//			if (map->matrix[line][column] == 'P')
//				char_count++;
//			column++;
//		}
//		line++;
//
//}


//void	*parse_map(t_vars *vars,
//{
//
//}