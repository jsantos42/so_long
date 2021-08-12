#ifndef MOVE_PLAYER_AND_UPDATE_POSITION_H
# define MOVE_PLAYER_AND_UPDATE_POSITION_H

# include "0_main.h"

int		move_player(char *current_position, char *new_position, int collectible_count);
void	update_player_position(t_matrix *map, int key);

#endif