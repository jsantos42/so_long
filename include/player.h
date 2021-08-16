#ifndef PLAYER_H
# define PLAYER_H

# include "main.h"

void	move_player(t_vars *vars, int key, char *current, char *new);
void	update_map(t_vars *vars, int key, int result);
void	update_player_position(t_matrix *map, int key);
void	update_player_rotation(t_vars *vars, int key);

#endif