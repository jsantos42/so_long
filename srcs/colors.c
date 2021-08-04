#include "../include/main.h"

/*
**	Creates an integer with a ARGB value.
**	A = alpha (transparency)
**	R = red
**	G = green
**	B = blue
**	Since an integer is 4 bytes (32 bits) in the architecture we're working, it
**	leaves 8 bits for each of the above values, which then can have 2^8 (256)
**	values.
**	The return line has 3 LEFT SHIFT operators and 3 binary OR operators that
**	place the binary values of the colors on the right spot of the int.
*/

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}