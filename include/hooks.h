#ifndef HOOKS_H
# define HOOKS_H

# include "main.h"

/*
**	KEYS
*/

# ifdef __linux__

#  define ESC			65307
#  define MV_UP_W 		119
#  define MV_DOWN_S 	115
#  define MV_RIGHT_D 	100
#  define MV_LEFT_A		97

# else
#  ifdef __APPLE__

#  define ESC			53
#  define MV_UP_W 		13
#  define MV_DOWN_S 	1
#  define MV_RIGHT_D 	2
#  define MV_LEFT_A		0
#  endif
# endif

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