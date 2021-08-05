#ifndef SO_LONG_MAIN_H
# define SO_LONG_MAIN_H

#include "../libs/minilibx_mms_20200219/mlx.h"
#include "../libs/libft/libft.h"

/*
**	ERRORS
*/

# define ILLEGAL_INPUT 1

typedef struct s_data {
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	int 	window_height;
	int		window_length;
}	t_data;

typedef struct s_color {
	int starting_x;
	int starting_y;
	int first_color;
	int second_color;
//	int orientation_angle; //to set the gradient
}	t_color;


void	error_management(int error);
void	win_img_init(void *connection, void **window, t_data *data);
t_color	colors_init(int starting_x, int starting_y, int first_color, int second_color);
int		on_key_press(int key, void *param);
int		on_click(int key, void *param);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	print_line(t_data *data, t_color colors, int line_size);
void	print_square(t_data *data, t_color	colors, int side_size);
void	print_circle(t_data *data, t_color colors, int radius);
int 		create_argb(int a, int r, int g, int b);
int		get_alpha(int argb);
int		get_red(int argb);
int		get_green(int argb);
int		get_blue(int argb);
int	increment_color(int first_color, int second_color, int distance);

#endif
