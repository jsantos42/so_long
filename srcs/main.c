#include "../include/main.h"

int main(int argc, char **argv)
{
	t_vars	*vars;

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
		print_map(vars);
		mlx_put_image_to_window(vars->connection, vars->window, vars->img, 0, 0);
		put_str_to_window(vars, "MOVES: 0");
		mlx_key_hook(vars->window, on_key_press, vars);
		mlx_hook(vars->window, DESTROY_NOTIFY, 1L, red_cross_click, vars->map);
		mlx_loop(vars->connection);
	}
	free(vars);
	return (0);
}

void	img_init(t_vars *vars)
{
	vars->window_width = vars->map->columns * IMG_WIDTH;
	vars->window_height = vars->map->lines * IMG_HEIGHT;
	vars->window = mlx_new_window(vars->connection, vars->window_width, vars->window_height, "SO LONG" );
	vars->img = mlx_new_image(vars->connection, vars->window_width, vars->window_height);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	vars->wall = load_image_as_texture(vars->connection, "imgs/wall.xpm");
	vars->free_space = load_image_as_texture(vars->connection, "imgs/free_space.xpm");
	vars->exit = load_image_as_texture(vars->connection, "imgs/exit.xpm");
	vars->enemy = load_image_as_texture(vars->connection, "imgs/enemy.xpm");
	vars->collectible = load_image_as_texture(vars->connection, "imgs/collectible.xpm");
	vars->player = load_image_as_texture(vars->connection, "imgs/player.xpm");
}
