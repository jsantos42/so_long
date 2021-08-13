#ifndef PLAYER_H
# define PLAYER_H

# include "0_main.h"

int		move_player(char *current_position, char *new_position, int collectible_count);
void	update_player_position(t_matrix *map, int key);
void	update_player_rotation(t_vars *vars, int key);

#endif