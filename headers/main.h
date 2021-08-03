#ifndef SO_LONG_MAIN_H
# define SO_LONG_MAIN_H

#include "../libs/minilibx_mms_20200219/mlx.h"
#include "../libs/libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}	t_data;


int on_click(int key, void *param);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	print_line(t_data *data, int x, int y, int color);
void	print_square(t_data *data, int starting_x, int starting_y, int size, int color);
void	print_circle(t_data *data, int center_x, int center_y, int radius, int color);
double  ft_power(double base, double exp);

#endif
