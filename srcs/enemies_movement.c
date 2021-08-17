#include "../include/enemies_movement.h"

static int	*get_moves_order(t_matrix *map);
static int	check_move(t_matrix *map, int enemy_i, int move);
static int	move_if_possible(char *position, t_matrix *map);

/*
**	This is a very simple way of moving the enemies around. It could be greatly
**	improved and would benefit of a random generator, but the subject limits the
**	usable functions.
**	For every move the player makes, it gets a different prefered order of
**	movements, by dividing the movement count by 3 prime numbers.
*/

void	move_enemies(t_matrix *map)
{
	int	enemy_i;
	int	j;
	int	*moves;

	moves = get_moves_order(map);
	enemy_i = 0;
	while (enemy_i < NUMBER_OF_ENEMIES)
	{
		j = 0;
		while (j < NUMBER_OF_MOVES)
		{
			if (check_move(map, enemy_i, moves[j]))
				break ;
			j++;
		}
		enemy_i++;
	}
	free(moves);
}

static int	*get_moves_order(t_matrix *map)
{
	int	*moves;
	int	iter;

	moves = malloc(sizeof(int) * NUMBER_OF_MOVES);
	iter = 0;
	while (iter < 4)
	{
		if (map->moves_count % 5 == 0)
			moves[iter] = MV_UP;
		else if (map->moves_count % 3 == 0)
			moves[iter] = MV_LEFT;
		else if (map->moves_count % 2 == 0)
			moves[iter] = MV_DOWN;
		else
			moves[iter] = MV_RIGHT;
		iter++;
	}
	return (moves);
}

static int	check_move(t_matrix *map, int enemy_i, int move)
{
	int	x;
	int	y;

	x = map->enemy_coord_x[enemy_i];
	y = map->enemy_coord_y[enemy_i];
	map->matrix[y][x] = '0';
	if (move == MV_UP && move_if_possible(&map->matrix[y - 1][x], map))
		map->enemy_coord_y[enemy_i]--;
	else if (move == MV_DOWN && move_if_possible(&map->matrix[y + 1][x], map))
		map->enemy_coord_y[enemy_i]++;
	else if (move == MV_LEFT && move_if_possible(&map->matrix[y][x - 1], map))
		map->enemy_coord_x[enemy_i]--;
	else if (move == MV_RIGHT && move_if_possible(&map->matrix[y][x + 1], map))
		map->enemy_coord_x[enemy_i]++;
	else
	{
		map->matrix[y][x] = 'T';
		return (0);
	}
	return (1);
}

static int	move_if_possible(char *position, t_matrix *map)
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
