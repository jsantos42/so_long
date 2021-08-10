#ifndef MOVE_PLAYER_H
# define MOVE_PLAYER_H

# include "main.h"

# define CONTINUE_GAME	0
# define FINISH_GAME	1
# define HIT_ENEMY		2

int	move_player(char *current_position, char *new_position, int collectible_count);

#endif