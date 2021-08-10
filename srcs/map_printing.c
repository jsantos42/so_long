#include "../include/map_printing.h"

void	print_map(t_vars *vars)
{
	int x;
	int y;
	t_color colors;

	vars->map->collectible_count = 0;
	y = 0;
	while (y < vars->map->lines)
	{
		x = 0;
		while (x < vars->map->columns)
		{
			if (vars->map->matrix[y][x] == '1')
				print_image(vars->wall, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			else if (vars->map->matrix[y][x] == '0')
			{
				colors = colors_init(x*IMG_WIDTH, y *IMG_HEIGHT, 0x000000, 0x000000);
				print_square(vars, colors, IMG_WIDTH);
			}
			else if (vars->map->matrix[y][x] == 'P')
			{
				print_image(vars->player, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
				vars->map->player_coord_x = x;
				vars->map->player_coord_y = y;
			}
			else if (vars->map->matrix[y][x] == 'C')
			{
				print_image(vars->collectible, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
				vars->map->collectible_count++;
			}
			else if (vars->map->matrix[y][x] == 'E')
				print_image(vars->exit, x * IMG_WIDTH, y * IMG_HEIGHT, vars);
			x++;
		}
		y++;
	}
}
