#include "../include/gradients.h"

///add this to libft
//static int ft_abs(int a)
//{
//	if (a < 0)
//		return (a * -1);
//	return (a);
//}

static int get_new_value(int (*f)(int), int first_color, int second_color, int distance)
{
	int	new_value;
	new_value = (f(second_color) - f(first_color)) / (distance - 1);
	return (new_value);
}

int	increment_color(int first_color, int second_color, int distance)
{
	int new_a;
	int new_r;
	int new_g;
	int	new_b;

	new_a = get_new_value(get_transparency, first_color, second_color, distance);
	new_r = get_new_value(get_red, first_color, second_color, distance);
	new_g = get_new_value(get_green, first_color, second_color, distance);
	new_b = get_new_value(get_blue, first_color, second_color, distance);
	return (new_a << 24 | new_r << 16 | new_g << 8 | new_b);
}

