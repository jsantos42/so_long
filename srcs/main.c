#include "../include/main.h"

int main(int argc, char **argv)
{
	void    *connection;
	void    *window;
	t_data	data;
	t_color colors;
	char	**map;

	if (argc != 2)
		error_management(ILLEGAL_INPUT);
	if (check_map_extension(argv[1]))
		error_management(WRONG_EXTENSION);
	map = import_map(argv[1]);
	//check if map is ok
/*
 The map must be composed of only 5 possible characters: 0 for an empty space, 1 for a wall, C for a collectible, E for map exit and P for the player’s starting position.
This is a simple valid map:
◦ The map must be closed/surrounded by walls, if not the program must return an error.
◦ Map must have at least one exit, one collectible, and one starting position.
◦ You don’t need to check if there’s a valid path in the map.
◦ The map must be rectangular.
◦ You must be able to parse any kind of map, as long as it respects the rules of the map.
 */
	connection = mlx_init();
	if (connection)
	{
		win_img_init(connection, &window, &data);

		// output shapes
		colors = colors_init(0, 3, 0x00FF00, 0xFF0000);
		print_line(&data, colors, 200);
		colors = colors_init(0, data.window_height - 4, 0xFF0000, 0x00FF00);
		print_line(&data, colors, data.window_length - 4);
		colors = colors_init(50, 100, 0xFF0000, 0x00FF00);
		print_square(&data, colors, 100);
		colors = colors_init(300, 300, 0x00FF00, 0x0000FF);
		print_circle(&data, colors, 100);
		mlx_put_image_to_window(connection, window, data.img, 0, 0);


		mlx_key_hook(window, on_key_press, (void *)0);
		mlx_mouse_hook(window, on_click, (void *)0);
		mlx_loop(connection);
	}
	return 0;
}

void	win_img_init(void *connection, void **window, t_data *data)
{
	data->window_length = 1280;
	data->window_height = 720;
	*window = mlx_new_window(connection, data->window_length, data->window_height, "mlx 42" );
	data->img = mlx_new_image(connection, data->window_length, data->window_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

t_color	colors_init(int starting_x, int starting_y, int first_color, int second_color)
{
	t_color	colors;

	colors.starting_x = starting_x;
	colors.starting_y = starting_y;
	colors.first_color = first_color;
	colors.second_color = second_color;
	return (colors);
}

