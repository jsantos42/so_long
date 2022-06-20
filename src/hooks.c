#include "../include/hooks.h"

/*
**	If the user presses the ESC key, the program frees the allocated memory and
**	exits (since there's no error, it passes 0 to free_matrix_and_exit.
**	If the user presses one of the moving keys (WASD), it calls its own action
**	by passing the current position of the player and the supposed new position
**	if the keystroke is indeed applied. This only changes the position of the
** 	chars on the map->matrix, before on_key_press can reprint the map to the
**	image/window.
**	The result variable's content will trigger the GAME OVER or YOU WON message.
*/

int	on_key_press(int key, t_vars *vars)
{
	int		x;
	int		y;
	char	*current_position;
	char	*new_position;

	x = vars->map->player_coord_x;
	y = vars->map->player_coord_y;
	current_position = &vars->map->matrix[y][x];
	if (key == ESC)
		free_vars_and_exit(0, vars);
	if ((key == MV_UP_W || key == MV_DOWN_S || key == MV_RIGHT_D || key == MV_LEFT_A)
		&& !vars->map->end_of_game)
	{
		if (key == MV_UP_W)
			new_position = &vars->map->matrix[y - 1][x];
		else if (key == MV_DOWN_S)
			new_position = &vars->map->matrix[y + 1][x];
		else if (key == MV_RIGHT_D)
			new_position = &vars->map->matrix[y][x + 1];
		else
			new_position = &vars->map->matrix[y][x - 1];
		move_player(vars, key, current_position, new_position);
	}
	return (0);
}

/*
**	This function is called when the user clicks the red cross button to close
**	the window. When doing so, it activates an X11 event called DESTROY_NOTIFY
**	and represented by an integer of value 17.
**	It's important to free all the allocated memory before terminating the
**	program. In this case, since it is no error, it gives 0 as an argument.
*/

int	red_cross_click(t_vars *vars)
{
	free_vars_and_exit(0, vars);
	return (0);
}
