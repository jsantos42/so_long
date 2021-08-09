#include "../include/main.h"

int main(int argc, char **argv)
{
	void    *connection;
	void    *window;
	t_vars	vars;
//	t_color colors;
	t_matrix	*map;

	if (argc != 2)
		error_management(ILLEGAL_INPUT);
	if (check_map_extension(argv[1]))
		error_management(WRONG_EXTENSION);
	map = import_map(argv[1]);

	connection = mlx_init();
	if (connection)
	{
		win_img_init(connection, &window, &vars, map);
		vars.brick = load_image_as_texture(connection, "/Users/jsantos/Desktop/so_long/imgs/brick.xpm");
		vars.beagle_boy = load_image_as_texture(connection, "/Users/jsantos/Desktop/so_long/imgs/beagle_boy.xpm");
		vars.coin = load_image_as_texture(connection, "/Users/jsantos/Desktop/so_long/imgs/coin.xpm");
		vars.uncle_scrooge = load_image_as_texture(connection, "/Users/jsantos/Desktop/so_long/imgs/uncle_scrooge.xpm");

		int x;
		int y;

		y = 0;
		while (y < map->lines)
		{
			x = 0;
			while (x < map->columns)
			{
				if (map->matrix[y][x] == '1')
					print_image(vars.brick, (x * 128), (y * 128), &vars);
				else if (map->matrix[y][x] == 'P')
					print_image(vars.uncle_scrooge, (x * 128), (y * 128), &vars);
				else if (map->matrix[y][x] == 'C')
					print_image(vars.coin, (x * 128), (y * 128), &vars);
				else if (map->matrix[y][x] == 'C')
					print_image(vars.coin, (x * 128), (y * 128), &vars);
				x++;
			}
			y++;
		}
//		print_image(vars.brick, 12*128, 0, &vars);

//		print_image(vars.coin, 200, 200, &vars);

//		mlx_put_image_to_window(connection, window, vars.brick, 50, 500);




		// output shapes
//		colors = colors_init(0, 3, 0x00FF00, 0xFF0000);
//		print_line(&vars, colors, 200);
//		colors = colors_init(0, vars.window_height - 4, 0xFF0000, 0x00FF00);
//		print_line(&vars, colors, vars.window_width - 4);
//		colors = colors_init(50, 100, 0xFF0000, 0x00FF00);
//		print_square(&vars, colors, 100);
//		colors = colors_init(300, 300, 0x00FF00, 0x0000FF);
//		print_circle(&vars, colors, 100);
		mlx_put_image_to_window(connection, window, vars.img, 0, 0);
//		mlx_string_put(connection, window, 50, 50, 0xFF0000, map->matrix[0]);//map->matrix[1]);
		mlx_key_hook(window, on_key_press, map);
		mlx_mouse_hook(window, on_click, map);
		mlx_hook(window, DESTROY_NOTIFY_X11_EVENT, 1L << 0, red_cross_clicking, map);
		mlx_loop(connection);
	}
	return 0;
}

void	win_img_init(void *connection, void **window, t_vars *vars, t_matrix *map)
{
	vars->window_width = map->columns * 128;
	vars->window_height = map->lines * 128;
	*window = mlx_new_window(connection, vars->window_width, vars->window_height, "mlx 42" );
	vars->img = mlx_new_image(connection, vars->window_width, vars->window_height);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
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

