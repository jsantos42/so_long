#include "../include/enemies.h"

/*
**	This is a very simple way of spotting 2 enemies on the map. The algo could
**	be seriously improved and would benefit of a random generator, but the
**	subject limits the usable functions.
*/

void	place_enemies(t_matrix *map)
{
	int x;
	int y;
	int	distance_between_enemies;
	int distance_iter;

	distance_between_enemies = find_char_in_map(map, '0') / 2;
	distance_iter = 0;
	y = 1;
	while (y < map->lines)
	{
		x = 1;
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
