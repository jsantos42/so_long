#include "../include/enemies.h"

void	place_enemies(t_matrix *map)
{
	int x;
	int y;
	int	distance_between_enemies;
	int distance_iter;

	distance_between_enemies = find_char_in_map(map, '0') / 4;
	distance_iter = 0;
	y = 0;
	while (y < map->lines)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->matrix[y][x] == '0')
			{
				distance_iter++;
				if (distance_iter == distance_between_enemies)
				{
					map->matrix[y][x] = 'T';
					distance_iter = 0;
				}
			}
			x++;
		}
		y++;
	}
}