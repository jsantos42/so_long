#include <stdio.h>
#include "../headers/main.h"

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42" );
	mlx_loop(mlx_ptr);
	return 0;
}

/*
 * add_shade is a function that accepts a double (distance) and a int (color) as arguments, 0 will add no shading to the
 * color, whilst 1 will make the color completely dark. 0.5 will dim it halfway, and .25 a quarter way. You get the point.
get_opposite is a function that accepts a int (color) as argument and that will invert the color accordingly.
 */

//void	add_shade(double distance, int color)
//{
//
//}