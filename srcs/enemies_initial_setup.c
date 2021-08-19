#include "../include/enemies_initial_setup.h"

static void	enemy_placer(t_map *map, t_enemies *bag);

/*
**	This is a very simple way of placing 2 enemies on the map. The algorithm
**	could be seriously improved and would benefit of a random generator, but the
**	subject limits the usable functions.
**	NOTE: because of the constraints imposed by the 42 Norm, I had to split the
**	function by creating an enemy_placer function and to define a new struct
**	type to pass all the needed variables.
*/

void	place_enemies(t_map *map)
{
	t_enemies	bag;

	bag.enemy_i = 0;
	bag.space_between_enemies = find_char_in_map(map, '0') / NUMBER_OF_ENEMIES;
	bag.space_i = 0;
	bag.y = 1;
	while (bag.y < map->lines && bag.enemy_i < NUMBER_OF_ENEMIES)
	{
		bag.x = 1;
		while (bag.x < map->columns && bag.enemy_i < NUMBER_OF_ENEMIES)
		{
			if (map->matrix[bag.y][bag.x] == '0')
			{
				bag.space_i++;
				if (bag.space_i == bag.space_between_enemies)
					enemy_placer(map, &bag);
			}
			bag.x++;
		}
		bag.y++;
	}
}

static void	enemy_placer(t_map *map, t_enemies *bag)
{
	map->matrix[bag->y][bag->x] = 'T';
	bag->space_i = 0;
	map->enemy_coord_x[bag->enemy_i] = bag->x;
	map->enemy_coord_y[bag->enemy_i] = bag->y;
	bag->enemy_i++;
}
