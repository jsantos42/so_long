#include <stdio.h>
#include "../headers/main.h"


typedef struct s_data {
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}	t_data;


int on_click(int key, void *param);
void	my_pixel_put(t_data *data, int x, int y, int color);


int main()
{
	void    *connection;
	void    *window;
	t_data	data;
	int		x;
	int 	y;

	connection = mlx_init();
	if (connection)
	{
		window = mlx_new_window(connection, 1920, 1080, "mlx 42" );
//		mlx_pixel_put(connection, window, 250, 250, 25500);
		data.img = mlx_new_image(connection, 1920, 1080);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		x = 0;
		y = 1;
		while (x < data.line_length) // && y < 10)
		{
			my_pixel_put(&data, x, y, 0x00FF0000);
			x++;
//			y++;
		}
		mlx_put_image_to_window(connection, window, data.img, 0, 0);
		mlx_key_hook(window, on_click, (void *)0);
		mlx_loop(connection);
	}
	return 0;
}

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


int on_click(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
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