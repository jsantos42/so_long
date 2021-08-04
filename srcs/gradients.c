#include "../include/main.h"

///add this to libft
static int ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

static int get_new_value(int (*f)(int), int first_color, int second_color, int distance)
{
	int	new_value;
	new_value = f(first_color) + (ft_abs(f(second_color) - f(first_color)) / (distance - 1));
	if (new_value > 255)
		new_value = 255;
	return (new_value);
}

int	set_gradient(int first_color, int second_color, int distance)
{
	int new_a;
	int new_r;
	int new_g;
	int	new_b;

	new_a = get_new_value(get_alpha, first_color, second_color, distance);
	new_r = get_new_value(get_red, first_color, second_color, distance);
	new_g = get_new_value(get_green, first_color, second_color, distance);
	new_b = get_new_value(get_blue, first_color, second_color, distance);
	return (new_a << 24 | new_r << 16 | new_g << 8 | new_b);
}

