#include "../headers/main.h"



int main()
{
	void    *connection;
	void    *window;
	t_data	data;
	int 	window_height;
	int		window_length;

	connection = mlx_init();
	if (connection)
	{
		window_length = 1920;
		window_height = 1080;
		window = mlx_new_window(connection, window_length, window_height, "mlx 42" );
		data.img = mlx_new_image(connection, window_length, window_height);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		print_line(&data, 0, 50, 255000000);
		print_line(&data, 0, window_height - 4, 255000000);
		print_square(&data, 500, 500, 50, 255000000);
		mlx_put_image_to_window(connection, window, data.img, 0, 0);
		mlx_key_hook(window, on_click, (void *)0);
		mlx_loop(connection);
	}
	return 0;
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