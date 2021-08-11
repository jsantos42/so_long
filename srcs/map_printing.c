#include "../include/map_printing.h"

void	print_map(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < vars->map->lines)
	{
		x = 0;
		while (x < vars->map->columns)
		{
			if (vars->map->matrix[y][x] == '1')
				print_image(vars->wall, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == '0')
				print_image(vars->free_space, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'P')
				print_image(vars->player, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'C')
				print_image(vars->collectible, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'E')
				print_image(vars->exit, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			x++;
		}
		y++;
	}
}

void	print_image(int **texture, int starting_x, int starting_y, t_vars *vars)
{
	int x;
	int y;

	y = starting_y;
	while (y <  starting_y + IMG_HEIGHT)
	{
		x = starting_x;
		while (x < starting_x + IMG_WIDTH)
		{
			my_pixel_put(vars, x, y, texture[y - starting_y][x - starting_x]);
			x++;
		}
		y++;
	}
}

void	reprint_map(t_vars *vars)
{
	char *str;

	str = ft_strjoin("MOVES: ", ft_itoa(vars->map->moves_count));
	print_map(vars);
	mlx_put_image_to_window(vars->connection, vars->window, vars->img, 0, 0);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	put_str_to_window(vars, str);
	free(str);
}