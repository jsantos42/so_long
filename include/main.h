#ifndef SO_LONG_MAIN_H
# define SO_LONG_MAIN_H

#include "../libs/minilibx_mms_20200219/mlx.h"
#include "../libs/libft/libft.h"
#include <fcntl.h>

/*
**	ERRORS
*/

# define ILLEGAL_INPUT		1
# define FAILED_MALLOC		2
# define WRONG_EXTENSION	3
# define ERROR_READING_MAP_FILE	4
# define INVALID_MAP		5
# define ERROR_READING_IMAGE_FILE 6


# define IMG_HEIGHT 128
# define IMG_WIDTH	128

# define DESTROY_NOTIFY_X11_EVENT	17
# define ESC				53

typedef struct s_vars {
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	int 	window_height;
	int		window_width;
	int 	**brick;
}	t_vars;

typedef struct s_temp {
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	int 	img_height;
	int		img_width;
}	t_temp;

typedef struct s_color {
	int starting_x;
	int starting_y;
	int first_color;
	int second_color;
//	int orientation_angle; //to set the gradient
}	t_color;

typedef struct s_matrix {
	char	**matrix;
	size_t 	lines;
	size_t	columns;
}	t_matrix;

int		check_map_extension(char *str);
t_matrix *import_map(char *str);
t_list	*map_lines_to_linked_list(int fd, size_t *line_count, size_t *line_length);
void	erase_str(void *str);
void	free_list_and_exit(int error, t_list *line_list);
void	free_matrix_and_exit(int error, t_matrix *map);
char	**linked_list_to_matrix(t_list *line_list, size_t line_count);
int		check_map_criteria(t_matrix *map);
int		find_char_in_map(t_matrix *map, char letter);
int		check_map_walls(t_matrix *map);
void	error_management(int error);
void	win_img_init(void *connection, void **window, t_vars *data);
t_color	colors_init(int starting_x, int starting_y, int first_color, int second_color);
int		on_key_press(int key, t_matrix *map);
int		on_click(int button, int x, int y, void *param);
int		red_cross_clicking(t_matrix *map);
void	my_pixel_put(t_vars *data, int x, int y, int color);
void	print_line(t_vars *data, t_color colors, int line_size);
void	print_square(t_vars *data, t_color	colors, int side_size);
void	print_circle(t_vars *data, t_color colors, int radius);
//void	print_image(t_vars *data, t_color colors, t_matrix *map, int side_size);
int 	create_trgb(int a, int r, int g, int b);
int		get_transparency(int trgb);
int		get_red(int trgb);
int		get_green(int trgb);
int		get_blue(int trgb);
int		increment_color(int first_color, int second_color, int distance);

int	**load_image_as_texture(void *connection, char *path);
//void	texture_init(char ***image);
void	texture_init(int ***image);
void	print_image(int **texture, int starting_x, int starting_y, t_vars *vars);

/*
** gnl stuff
*/

# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 2

typedef struct s_args
{
	int		reading;
	char	*temp;
	int		nl_index;
}	t_args;

char	*ft_left_over(char const *s, unsigned int start);
int		get_nl_chr(char *str);
int		get_next_line(int fd, char **line);
void	carry_checker(char **carry, char *buff, t_args args);
int		ft_line_writer(int fd, char **line, t_args args, char **carry);

#endif
