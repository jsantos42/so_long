#ifndef COLORS_H
# define COLORS_H

#include "main.h"

int	create_trgb(int t, int r, int g, int b);
int	get_transparency(int trgb);
int	get_red(int trgb);
int	get_green(int trgb);
int	get_blue(int trgb);

#endif