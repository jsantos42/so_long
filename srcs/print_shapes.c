#include "../include/main.h"

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


/////protect against printing outside of window



void	print_line(t_vars *vars, t_color colors, int line_size)
{
	int	temp_color;
	int x;
	int y;

	x = colors.starting_x;
	y = colors.starting_y;
	temp_color = colors.first_color;
	while (x < colors.starting_x + line_size)
	{
		if (colors.first_color != colors.second_color)
			temp_color += increment_color(temp_color, colors.second_color, line_size);
		my_pixel_put(vars, x, y, temp_color);
		x++;
	}
}

void	print_square(t_vars *vars, t_color	colors, int side_size)
{
	int	temp_color;
	int x;
	int y;

	y = colors.starting_y;
	while (y <  colors.starting_y + side_size)
	{
		x = colors.starting_x;
		temp_color = colors.first_color;
		while (x < colors.starting_x + side_size)
		{
			if (colors.first_color != colors.second_color)
				temp_color += increment_color(temp_color, colors.second_color, side_size);
			my_pixel_put(vars, x, y, temp_color);
			x++;
		}
		y++;
	}
}

void	print_circle(t_vars *vars, t_color colors, int radius)
{
	int	temp_color;
	int x;
	int y;

	y = colors.starting_y - radius;
	while (y < colors.starting_y + radius)
	{
		x = colors.starting_x - radius;
		temp_color = colors.first_color;
		while (x < colors.starting_x + radius)
		{
			if (ft_power(x - colors.starting_x, 2)
			+ ft_power(y - colors.starting_x, 2) <= ft_power(radius, 2))
			{
				if (colors.first_color != colors.second_color)
					temp_color += increment_color(colors.first_color, colors.second_color, radius * 2);
				my_pixel_put(vars, x, y, temp_color);
			}
			x++;
		}
		y++;
	}
}
