#include "../include/map_printing.h"

/*
**	If the game is finished (because the player either won or lost), it prints
**	a black overlay and the respective message. Otherwise, it reprints the map.
*/

void	print_map(t_vars *vars)
{
	char	*str;

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

/*
**	Reads the overlay black texture and prints its pixels to the image that is
**	going to be manipulated and displayed on the window.
*/

void	print_overlay(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map->lines)
	{
		x = 0;
		while (x < vars->map->columns)
		{
			print_texture(vars->end, x * WIDTH, y * HEIGHT, vars);
			x++;
		}
		y++;
	}
}

/*
**	Goes through the various chars of the map and decides accordingly which
**	texture to print on the corresponding image location.
 *	NOTE: due to the limitations imposed by 42's Norm, I had to break line 78
 *	and start the iterations on -1 and increasing on the while checking (this
 *	allows me to save 2 lines and spares me from splitting the function.
*/

void	choose_texture_to_print(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map->lines)
	{
		x = -1;
		while (++x < vars->map->columns)
		{
			if (vars->map->matrix[y][x] == '1')
				print_texture(vars->wall, x * WIDTH, y * HEIGHT, vars);
			else if (vars->map->matrix[y][x] == '0')
				print_texture(vars->free_space, x * WIDTH, y * HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'P')
				print_texture(vars->map->player_rotation, x * WIDTH,
					  y * HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'C')
				print_texture(vars->collectible, x * WIDTH, y * HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'T')
				print_texture(vars->enemy, x * WIDTH, y * HEIGHT, vars);
			else if (vars->map->matrix[y][x] == 'E')
				print_texture(vars->exit, x * WIDTH, y * HEIGHT, vars);
		}
	}
}

/*
**	Reads the texture and prints its pixels to the image. This image is the one
**	that is going to be manipulated and displayed on the window.
*/

void	print_texture(int **texture, int start_x, int start_y, t_vars *vars)
{
	int	x;
	int	y;

	y = start_y;
	while (y < start_y + HEIGHT)
	{
		x = start_x;
		while (x < start_x + WIDTH)
		{
			put_pixel_to_window(vars, x, y,
				   texture[y - start_y][x - start_x]);
			x++;
		}
		y++;
	}
}
