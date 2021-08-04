#include "../include/main.h"

//int	set_gradient(int first_color, int second_color, int distance)
//{
//	int a_increment;
//	int r_increment;
//	int g_increment;
//	int	b_increment;
//
//
//	a_increment = (get_alpha(second_color) - get_alpha(first_color)) / distance;
//	r_increment = (get_red(second_color) - get_red(first_color)) / distance;
//	g_increment = (get_green(second_color) - get_green(first_color)) / distance;
//	b_increment = (get_blue(second_color) - get_blue(first_color)) / distance;
////	return (first_color + ((a_increment) << 24 | r_increment << 16 | g_increment << 8 | b_increment));
//	return (get_alpha(first_color) + a_increment << 24
//	| (get_red(first_color) + r_increment ) << 16
//	| (get_green(first_color) + g_increment) << 8
//	| (get_blue(first_color) + b_increment));
//}

int get_new_value(int (*f)(int), int first_color, int second_color, int distance);

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

int get_new_value(int (*f)(int), int first_color, int second_color, int distance)
{
	int	new_value;
	new_value = f(first_color) + ((f(second_color) - f(first_color)) / (distance -1));
	if (new_value > 255)
		new_value = 255;
	return (new_value);
}