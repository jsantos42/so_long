#include "../include/9_move_player_and_update_position.h"

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

int	move_player(char *current_position, char *new_position, int collectible_count)
{
	if (*new_position == '1' || (*new_position == 'E' && collectible_count != 0))
		return (NOT_ALLOWED);
	*current_position = '0';
	if (*new_position == 'E' && collectible_count == 0)
		return (FINISH_GAME);
	if (*new_position == 'T')
		return (GAMEOVER);
	if (*new_position == 'C')
	{
		*new_position = 'P';
		return (CAUGHT_COLLECTIBLE);
	}
	else
	{
		*new_position = 'P';
		return (SUCCESSFUL_MOVE);
	}
}

/*
**	Updates the player's position according to the accepted key.
*/

void	update_player_position(t_matrix *map, int key)
{
	if (key == MOVE_UP)
		map->player_coord_y--;
	else if (key == MOVE_DOWN)
		map->player_coord_y++;
	else if (key == MOVE_RIGHT)
		map->player_coord_x++;
	else if (key == MOVE_LEFT)
		map->player_coord_x--;
}


void	update_player_rotation(t_vars *vars, int key)
{
	if (key == MOVE_RIGHT)
		vars->map->player_current_rotation = vars->player_right;
	else if (key == MOVE_LEFT)
		vars->map->player_current_rotation = vars->player_left;
}
