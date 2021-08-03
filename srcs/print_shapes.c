#include "../headers/main.h"

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


void	print_line(t_data *data, int x, int y, int color)
{
	while (x < data->line_length)
	{
		my_pixel_put(data, x, y, color);
		x++;
	}
}

void	print_square(t_data *data, int starting_x, int starting_y, int size, int color)
{
	int x;
	int y;

	x = starting_x;
	y = starting_y;
	while (y <  starting_y + size)
	{
		x = starting_x;
		while (x < starting_x + size)
		{
			my_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_circle(t_data *data, int center_x, int center_y, int radius, int color)
{
	int x;
	int y;

	x = center_x - radius;
	y = center_y - radius;
	while (y < center_y + radius)
	{
		x = center_x - radius;
		while (x < center_x + radius)
		{
			if (ft_power(x - center_x, 2) + ft_power(y - center_y, 2) <= ft_power(radius, 2))
				my_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}


int	ft_power(int base, int exp)
{
	if (exp == 0)
		return (1);
	else
		return (base * ft_power(base, exp - 1));
}