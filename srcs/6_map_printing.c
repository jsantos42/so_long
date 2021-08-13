#include "../include/6_map_printing.h"

void	print_map(t_vars *vars)
{
	char *str;

	if (vars->map->end_of_game == 1)
	{
		str = ft_strdup("YOU WON");
		print_overlay(vars);
	}
	else if (vars->map->end_of_game == -1)
	{
		str = ft_strdup("GAME OVER");
		print_overlay(vars);
	}
	else
	{
		str = ft_strjoin("MOVES: ", ft_itoa(vars->map->moves_count));
		choose_texture_to_print(vars);
	}
	mlx_put_image_to_window(vars->connection, vars->window, vars->img, 0, 0);
	put_str_to_window(vars, str);
	free(str);
}

void	choose_texture_to_print(t_vars *vars)
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
				print_texture(vars->wall, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == '0')
				print_texture(vars->free_space, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'P')
				print_texture(vars->map->player_current_rotation, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'C')
				print_texture(vars->collectible, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'T')
				print_texture(vars->enemy, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'E')
				print_texture(vars->exit, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			x++;
		}
		y++;
	}
}

void	print_texture(int **texture, int starting_x, int starting_y, t_vars *vars)
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

void	print_overlay(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < vars->map->lines)
	{
		x = 0;
		while (x < vars->map->columns)
		{
			print_texture(vars->end, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			x++;
		}
		y++;
	}
}
