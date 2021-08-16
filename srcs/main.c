#include "../include/main.h"

/*
**	1) Starts by checking the number of arguments.
**	2) Checks the  extension of the map file passed as an argument.
**	3) Imports the map from the file to a matrix.
**	4) Initiates the connection to a window with MiniLibX. If establishing the
**	connection fails, frees the allocated memory before exiting.
**	5) Initiates the window and gets the parameters needed to create an image
**	that is going to be manipulated and displayed on that window.
**	6) Loads the image files (extension .xmp due to the requirements of the MLX)
**	to matrices of ints. Each int (of size 32bits) represents a pixel, with each
**	of the 4 bytes representing a channel of TRGB (in this case, due to the
**	requirements of the MLX, T is transparency and not alpha/opacity).
**	7) Sets the initial rotation of the player texture, which will be useful
**	when running the program with BONUS=1, which allows the player texture to
**	flip horizontally according to its movements.
**	8) Defines a hook that each keyboard key press calls the function
**	on_key_press. This will allow both closing the window (ESC key) and moving
**	the player around (WASD keys).
**	9) Defines a second hook for the X11 event called when clicking the red
**	cross button on the upper left corner of the window. This event closes the
**	window and is called Destroy Notify.
**	10) In order for the window to remain open and not terminating the program,
**	we call mlx_loop which allows for an infinite loop.
*/

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		error_management(ILLEGAL_INPUT);
	if (check_map_extension(argv[1]))
		error_management(WRONG_EXTENSION);
	vars = import_map(argv[1]);
	vars->connection = mlx_init();
	if (!vars->connection)
		free_vars_and_exit(NO_CONNECTION, vars);
	win_img_init(vars);
	load_textures(vars);
	vars->map->player_rotation = vars->player_right;
	print_map(vars);
	mlx_key_hook(vars->window, on_key_press, vars);
	mlx_hook(vars->window, DESTROY_NOTIFY, 1L, red_cross_click, vars->map);
	mlx_loop(vars->connection);
	return (0);
}

void	win_img_init(t_vars *vars)
{
	vars->window_width = vars->map->columns * WIDTH;
	vars->window_height = vars->map->lines * HEIGHT;
	vars->window = mlx_new_window(vars->connection, vars->window_width,
			   vars->window_height, "SO LONG" );
	if (!vars->window)
		free_vars_and_exit(NO_WINDOW, vars);
	vars->img = mlx_new_image(vars->connection, vars->window_width,
			   vars->window_height);
	if (!vars->img)
		free_vars_and_exit(NO_IMG, vars);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}
