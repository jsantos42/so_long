#ifndef HOOKS_H
# define HOOKS_H

# include "main.h"

/*
**	KEYS
*/

# define ESC				53
# define MV_UP 			13
# define MV_DOWN 			1
# define MV_RIGHT 		2
# define MV_LEFT			0

/*
**	RESULT OF THE MOVE
*/

# define NOT_ALLOWED		0
# define SUCCESSFUL_MOVE	1
# define CAUGHT_COLLECTIBLE	2
# define FINISH_GAME		3
# define GAMEOVER			4

int	on_key_press(int key, t_vars *vars);
int	red_cross_click(t_vars *vars);

#endif