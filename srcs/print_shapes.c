#include "../include/main.h"

/*
**	Here dst gets the sum  of the address of the origin (coordinates 0,0, the
**	leftmost and uppermost point) and the offset of the desired coordinates
**	(in order to print to pixel (5,5), for example, it needs to go down y times
**	(and each step it goes down corresponds to a whole line_length) and needs
**	to go right x times (and each step it goes right corresponds to the number
**	of bytes used in each pixel).
*/

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + (x * (data->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}


void	print_line(t_data *data, t_color *colors, int line_size)
{
	int x;
	int y;

	x = colors->starting_x;
	y = colors->starting_y;
	while (x < colors->starting_x + line_size)
	{
		my_pixel_put(data, x, y, colors->first_color);
		x++;
	}
}

void	print_square(t_data *data, t_color	*colors, int side_size)
{
	int x;
	int y;

	x = colors->starting_x;
	y = colors->starting_y;
	while (y <  colors->starting_y + side_size)
	{
		x = colors->starting_x;
		while (x < colors->starting_x + side_size)
		{
			my_pixel_put(data, x, y, colors->first_color);
			x++;
		}
		y++;
	}
}

void	print_circle(t_data *data, t_color *colors, int radius)
{
	int x;
	int y;

	x = colors->starting_x - radius;
	y = colors->starting_y - radius;
	while (y < colors->starting_y + radius)
	{
		x = colors->starting_x - radius;
		while (x < colors->starting_x + radius)
		{
			if (ft_power(x - colors->starting_x, 2) + ft_power(y - colors->starting_x, 2) <= ft_power(radius, 2))
				my_pixel_put(data, x, y, colors->first_color);
			x++;
		}
		y++;
	}
}


