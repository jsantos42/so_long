#include "../include/move_player.h"

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
	char	temp;

	if (*new_position == 'E' && collectible_count == 0)
	{
		*current_position = '0';
		return (FINISH_GAME);
	}
	if (*new_position == 'T')
	{
		*current_position = '0';
		return (GAMEOVER);
	}
	if (*new_position == 'C')
		*new_position = '0';
	if (*new_position == '0')
	{
		temp = *new_position;
		*new_position = *current_position;
		*current_position = temp;
		return (SUCCESSFUL_MOVE);
	}
	return (NOT_ALLOWED);
}

