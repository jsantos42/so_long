#ifndef HOOKS_H
# define HOOKS_H

#include "main.h"

/*
**	KEYS
*/

# define ESC				53
# define MOVE_UP 			126
# define MOVE_DOWN 			125
# define MOVE_RIGHT 		124
# define MOVE_LEFT			123

int on_key_press(int key, t_vars *vars);
int	on_click(int button, int x, int y, void *param);
int red_cross_clicking(t_matrix *map);

#endif