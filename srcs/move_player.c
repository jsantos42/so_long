#include "../include/move_player.h"

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

