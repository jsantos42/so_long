#include "../include/player.h"

/*
**	Checks what's on new_position (the position the player would go to in case
**	the keystroke takes effect.
**	 - If it's the exit, it will only allowed the player in if there are no
**	 more collectibles left.
**	 - If it's the collectible it disappears and the player can go to that spot.
**	 - If it's a empty spot the player can also move there.
**	 This function changes the position of the chars on the map->matrix and the
**	 previous function (on_key_press) reprints the map.
*/

void	move_player(t_vars *vars, int key, char *current, char *new)
{
	int	result;

	if (*new == '1' || (*new == 'E' && vars->map->collectible_count != 0))
		return ;
	*current = '0';
	if (*new == 'E' && vars->map->collectible_count == 0)
		result = FINISH_GAME;
	else if (*new == 'T')
		result = GAMEOVER;
	else if (*new == 'C')
	{
		*new = 'P';
		result = CAUGHT_COLLECTIBLE;
	}
	else
	{
		*new = 'P';
		result = SUCCESSFUL_MOVE;
	}
	update_map(vars, key, result);
}

void	update_map(t_vars *vars, int key, int result)
{
	vars->map->moves_count++;
	if (result == CAUGHT_COLLECTIBLE)
		vars->map->collectible_count--;
	if (result == GAMEOVER)
		vars->map->end_of_game = -1;
	if (result == FINISH_GAME)
		vars->map->end_of_game = 1;
	update_player_position(vars->map, key);
	if (BONUS)
	{
		update_player_rotation(vars, key);
		move_enemies(vars->map);
	}
	print_map(vars);
}

/*
**	Updates the player's position according to the accepted key.
*/

void	update_player_position(t_map *map, int key)
{
	if (key == MV_UP_W)
		map->player_coord_y--;
	else if (key == MV_DOWN_S)
		map->player_coord_y++;
	else if (key == MV_RIGHT_D)
		map->player_coord_x++;
	else if (key == MV_LEFT_A)
		map->player_coord_x--;
}

void	update_player_rotation(t_vars *vars, int key)
{
	if (key == MV_RIGHT_D)
		vars->map->player_rotation = vars->player_right;
	else if (key == MV_LEFT_A)
		vars->map->player_rotation = vars->player_left;
}
