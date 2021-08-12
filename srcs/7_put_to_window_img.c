#include "../include/7_put_to_window_img.h"

/*
**	Here dst gets the sum  of the address of the origin (coordinates 0,0, the
**	leftmost and uppermost point) and the offset of the desired coordinates
**	(in order to print to pixel (5,5), for example, it needs to go down y times
**	(and each step it goes down corresponds to a whole line_length) and needs
**	to go right x times (and each step it goes right corresponds to the number
**	of bytes used in each pixel).
*/

void	my_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + (x * (vars->bits_per_pixel / 8)));
	*(int *)dst = color;
}


/*
**	Allows cleaner code, since the MiniLibX built-in function demands a lot of
**	parameters. Ideally, this function would still get text_color, text_x and
**	text_y as parameters, but this program only needs to print in one place and
**	in one color, so this simpler function is enough.
*/

void	put_str_to_window(t_vars *vars, char *str)
{
	int	x;
	int	y;
	int	color;

	x = vars->map->text_x;
	y = vars->map->text_y;
	color = vars->map->text_color;
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	mlx_string_put(vars->connection, vars->window, x, y, color, str);
}