#include "../include/main.h"

int main(int argc, char **argv)
{
	t_vars		*vars;
//	t_color colors;

	if (argc != 2)
		error_management(ILLEGAL_INPUT);
	if (check_map_extension(argv[1]))
		error_management(WRONG_EXTENSION);
	vars = malloc(sizeof(t_vars));
	vars->map = import_map(argv[1]);
	vars->connection = mlx_init();
	if (vars->connection)
	{
		img_init(vars);
		vars->window = mlx_new_window(vars->connection, vars->window_width, vars->window_height, "mlx 42" );
		print_map(vars);




		// output shapes
//		colors = colors_init(0, 3, 0x00FF00, 0xFF0000);
//		print_line(&vars, colors, 200);
//		colors = colors_init(0, vars.window_height - 4, 0xFF0000, 0x00FF00);
//		print_line(&vars, colors, vars.window_width - 4);
//		colors = colors_init(50, 100, 0xFF0000, 0x00FF00);
//		print_square(&vars, colors, 100);
//		colors = colors_init(300, 300, 0x00FF00, 0x0000FF);
//		print_circle(&vars, colors, 100);
		mlx_put_image_to_window(vars->connection, vars->window, vars->img, 0, 0);
//		mlx_string_put(connection, window, 50, 50, 0xFF0000, map->matrix[0]);//map->matrix[1]);
		mlx_key_hook(vars->window, on_key_press, vars);
		mlx_mouse_hook(vars->window, on_click, vars);
		mlx_hook(vars->window, DESTROY_NOTIFY_X11_EVENT, 1L << 0, red_cross_clicking, vars->map);
		mlx_loop(vars->connection);
	}
	free(vars);
	return (0);
}

void	img_init(t_vars *vars)
{
	vars->window_width = vars->map->columns * IMG_WIDTH;
	vars->window_height = vars->map->lines * IMG_HEIGHT;
	vars->img = mlx_new_image(vars->connection, vars->window_width, vars->window_height);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	vars->brick = load_image_as_texture(vars->connection, "imgs/brick.xpm");
	vars->beagle_boy = load_image_as_texture(vars->connection, "imgs/beagle_boy.xpm");
	vars->coin = load_image_as_texture(vars->connection, "imgs/coin.xpm");
	vars->uncle_scrooge = load_image_as_texture(vars->connection, "imgs/uncle_scrooge.xpm");
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


void	print_map(t_vars *vars)
{
	int x;
	int y;
	t_color colors;

	y = 0;
	while (y < vars->map->lines)
	{
		x = 0;
		while (x < vars->map->columns)
		{
			if (vars->map->matrix[y][x] == '1')
				print_image(vars->brick, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == '0')
			{
				colors = colors_init(x*IMG_WIDTH, y *IMG_HEIGHT, 0x000000, 0x000000);
				print_square(vars, colors, IMG_WIDTH);
			}
			else if (vars->map->matrix[y][x] == 'P')
			{
				print_image(vars->uncle_scrooge, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
				vars->map->player_coord_x = x;
				vars->map->player_coord_y = y;
			}
			else if (vars->map->matrix[y][x] == 'C')
				print_image(vars->coin, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
//			else if (vars->map->matrix[y][x] == 'E')
//				print_image(vars->exit, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			x++;
		}
		y++;
	}
}