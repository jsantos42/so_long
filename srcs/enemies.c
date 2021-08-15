#include "../include/enemies.h"

/*
**	This is a very simple way of placing 2 enemies on the map. The algorithm
**	could be seriously improved and would benefit of a random generator, but the
**	subject limits the usable functions.
*/

void	place_enemies(t_matrix *map)
{
	int x;
	int y;
	int enemy_count;
	int	distance_between_enemies;
	int distance_iter;

	enemy_count = 0;
	distance_between_enemies = find_char_in_map(map, '0') / NUMBER_OF_ENEMIES;
	distance_iter = 0;
	y = 1;
	while (y < map->lines && enemy_count < NUMBER_OF_ENEMIES)
	{
		x = 1;
		while (x < map->columns && enemy_count < NUMBER_OF_ENEMIES)
		{
			if (map->matrix[y][x] == '0')
			{
				distance_iter++;
				if (distance_iter == distance_between_enemies)
				{
					map->matrix[y][x] = 'T';
					distance_iter = 0;
					map->enemy_coord_x[enemy_count] = x;
					map->enemy_coord_y[enemy_count] = y;
					enemy_count++;
				}
			}
			x++;
		}
		y++;
	}
}

void	move_enemies(t_matrix *map)
{
	int	i;
	int x;
	int y;

	i = 0;
	while (i < NUMBER_OF_ENEMIES)
	{
		x = map->enemy_coord_x[i];
		y = map->enemy_coord_y[i];
		map->matrix[y][x] = '0';
		if (map->matrix[y - 1][x] == '0')
		{
			map->matrix[y - 1][x] = 'T';
			map->enemy_coord_y[i]--;
		}
		else if (map->matrix[y][x - 1] == '0')
		{
			map->matrix[y][x - 1] = 'T';
			map->enemy_coord_x[i]--;
		}
		else if (map->matrix[y + 1][x] == '0')
		{
			map->matrix[y + 1][x] = 'T';
			map->enemy_coord_y[i]++;
		}
		else if (map->matrix[y][x + 1] == '0')
		{
			map->matrix[y][x + 1] = 'T';
			map->enemy_coord_x[i]++;
		}
		else
			map->matrix[y][x] = 'T';
		i++;
	}
}
