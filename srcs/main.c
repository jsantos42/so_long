#include "../include/main.h"

int main()
{
	void    *connection;
	void    *window;
	t_data	data;
	t_color colors;

	connection = mlx_init();
	if (connection)
	{
		win_img_init(connection, &window, &data);
		colors = colors_init(0, 3, 0xFF0000, 0x00FF00);
		print_line(&data, colors, 200);
		colors = colors_init(0, data.window_height - 4, 0xFF0000, 0x00FFFF);
		print_line(&data, colors, data.window_length);
		colors = colors_init(50, 100, 0xFF0000, 0x00FF00);
		print_square(&data, colors, 100);
		colors = colors_init(300, 300, 0x00FF00, 0x0000FF);
		print_circle(&data, colors, 100);
		mlx_put_image_to_window(connection, window, data.img, 0, 0);
		mlx_key_hook(window, on_click, (void *)0);
		mlx_loop(connection);
	}
	return 0;
}

void	win_img_init(void *connection, void **window, t_data *data)
{
	data->window_length = 1280;
	data->window_height = 720;
	*window = mlx_new_window(connection, data->window_length, data->window_height, "mlx 42" );
	data->img = mlx_new_image(connection, data->window_length, data->window_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

t_color	colors_init(int starting_x, int starting_y, int first_color, int second_color)
{
	t_color	colors;

	colors.starting_x = starting_x;
	colors.starting_y = starting_y;
	colors.first_color = first_color;
	colors.second_color = second_color;
	return (colors);
}

int on_click(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
