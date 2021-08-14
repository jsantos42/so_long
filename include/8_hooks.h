#ifndef HOOKS_H
# define HOOKS_H

#include "0_main.h"

/*
**	KEYS
*/

# define ESC				53
# define MOVE_UP 			13
# define MOVE_DOWN 			1
# define MOVE_RIGHT 		2
# define MOVE_LEFT			0

# define NOT_ALLOWED		0
# define SUCCESSFUL_MOVE	1
# define CAUGHT_COLLECTIBLE	2
# define FINISH_GAME		3
# define GAMEOVER			4

int on_key_press(int key, t_vars *vars);
int	on_click(int button, int x, int y, void *param);
int red_cross_click(t_vars *vars);

#endif