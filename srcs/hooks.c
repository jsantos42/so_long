#include "../include/hooks.h"

/*
**	If the user presses the ESC key, the program frees the allocated memory and
**	exits (since there's no error, it passes 0 to free_matrix_and_exit.
**	If the user presses one of the moving keys (WASD), it calls its own action
**	by passing the current position of the player and the supposed new position
**	if the keystroke is indeed applied. This only changes the position of the
** 	chars on the map->matrix, before on_key_press can reprint the map to the
**	image/window.
**	The result variable's content will trigger the GAMEOVER or FINISHED_GAME
**	message.
*/

///print the message based on the result value.

int on_key_press(int key, t_vars *vars)
{
	int x;
	int y;
	int result;

	x = vars->map->player_coord_x;
	y = vars->map->player_coord_y;
	result = NOT_ALLOWED;
	if (key == ESC)
	{
		//mlx_destroy_window needed??
		free_matrix_and_exit(0, vars->map);
	}
	else if (key == MOVE_UP)
		result = move_player(&vars->map->matrix[y][x], &vars->map->matrix[y - 1][x], vars->map->collectible_count);
	else if (key == MOVE_DOWN)
		result = move_player(&vars->map->matrix[y][x], &vars->map->matrix[y + 1][x], vars->map->collectible_count);
	else if (key == MOVE_RIGHT)
		result = move_player(&vars->map->matrix[y][x], &vars->map->matrix[y][x + 1], vars->map->collectible_count);
	else if (key == MOVE_LEFT)
		result = move_player(&vars->map->matrix[y][x], &vars->map->matrix[y][x - 1], vars->map->collectible_count);
	if (result != NOT_ALLOWED)
	{
		vars->map->moves_count++;
		if (result == CAUGHT_COLLECTIBLE)
			vars->map->collectible_count--;
		update_player_position(vars->map, key);
		reprint_map(vars);
	}
	return (0);
}

int	on_click(int button, int x, int y, void *param)
{
	(void)param;

	ft_putnbr_fd(button, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(y, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

/*
**	This function is called when the user clicks the red cross button to close
**	the window. When doing so, it activates an X11 event called DESTROY_NOTIFY
**	and represented by an integer of value 17.
**	It's important to free all the allocated memory before terminating the
**	program. In this case, since it is no error, it gives 0 as an argument.
*/

int red_cross_click(t_matrix *map)
{
	//mlx_destroy_window needed??
	free_matrix_and_exit(0, map);
	return (0);
}
