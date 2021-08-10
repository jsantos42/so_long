#ifndef PRINT_SHAPES_H
# define PRINT_SHAPES_H

#include "main.h"

void	my_pixel_put(t_vars *vars, int x, int y, int color);
void	print_line(t_vars *vars, t_color colors, int line_size);
void	print_square(t_vars *vars, t_color	colors, int side_size);
void	print_circle(t_vars *vars, t_color colors, int radius);

#endif