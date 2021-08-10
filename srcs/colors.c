#include "../include/colors.h"

/*
**	Creates an unsigned integer with a ARGB value.
**	T = transparency (for historical reasons, on the MiniLibX the alpha byte
**	represents transparency instead of opacity)
**	R = red
**	G = green
**	B = blue
**	Since an integer is 4 bytes (32 bits) in the architecture we're working, it
**	leaves 8 bits for each of the above values, which then can have 2^8 (256)
**	values.
**	The return line has 3 LEFT SHIFT operators and 3 binary OR operators that
**	place the binary values of the colors on the right spot of the integer.
*/

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
**	The following 4 functions extract one value from the ARGB color, through a
**	binary AND operation and binary SHIFT operations. Note that it needs to do
**	the second binary shift (to the right) so that it can return a value between
**	0-255.
*/

int	get_transparency(int trgb)
{
	return ((trgb & (0xFF << 24)) >> 24);
}

int	get_red(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

int	get_green(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

int	get_blue(int trgb)
{
	return (trgb & 0xFF);
}
