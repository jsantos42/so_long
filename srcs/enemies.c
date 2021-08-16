#include "../include/enemies.h"

static void	enemy_placer(t_matrix *map, t_enemies *bag);
static int	check_before_moving_enemy(char *position, t_matrix *map);

/*
**	This is a very simple way of placing 2 enemies on the map. The algorithm
**	could be seriously improved and would benefit of a random generator, but the
**	subject limits the usable functions.
**	NOTE: because of the constraints imposed by the 42 Norm, I had to split the
**	function by creating an enemy_placer function and to define a new struct
**	type to pass all the needed variables.
*/

void	place_enemies(t_matrix *map)
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

static void	enemy_placer(t_matrix *map, t_enemies *bag)
{
	map->matrix[bag->y][bag->x] = 'T';
	bag->space_i = 0;
	map->enemy_coord_x[bag->enemy_i] = bag->x;
	map->enemy_coord_y[bag->enemy_i] = bag->y;
	bag->enemy_i++;
}

/*
**	This is a very simple way of moving the enemies around. It could be greatly
**	improved and would benefit of a random generator, but the subject limits the
**	usable functions. The way it's conceived, the enemies end up in a a corner
**	doing the same moves all the time after a while and, in some maps, make it
**	impossible to move around or catch all coins.
*/

void	move_enemies(t_matrix *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < NUMBER_OF_ENEMIES)
	{
		x = map->enemy_coord_x[i];
		y = map->enemy_coord_y[i];
		map->matrix[y][x] = '0';
		if (check_before_moving_enemy(&map->matrix[y - 1][x], map))
			map->enemy_coord_y[i]--;
		else if (check_before_moving_enemy(&map->matrix[y + 1][x], map))
			map->enemy_coord_y[i]++;
		else if (check_before_moving_enemy(&map->matrix[y][x - 1], map))
			map->enemy_coord_x[i]--;
		else if (check_before_moving_enemy(&map->matrix[y][x + 1], map))
			map->enemy_coord_x[i]++;
		else
			map->matrix[y][x] = 'T';
		i++;
	}
}

static int	check_before_moving_enemy(char *position, t_matrix *map)
{
	if (*position == '0')
	{
		*position = 'T';
		return (1);
	}
	else if (*position == 'P')
	{
		*position = 'T';
		map->end_of_game = -1;
		return (1);
	}
	else
		return (0);
}
