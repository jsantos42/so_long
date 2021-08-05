#ifndef SO_LONG_MAIN_H
# define SO_LONG_MAIN_H

#include "../libs/minilibx_mms_20200219/mlx.h"
#include "../libs/libft/libft.h"
#include <fcntl.h>

/*
**	ERRORS
*/

# define ILLEGAL_INPUT		1
# define WRONG_EXTENSION	2
# define ERROR_READING_FILE	3
# define WRONG_MAP_SHAPE	4

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


int		check_map_extension(char *str);
char	**import_map(char **str);
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

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_left_over(char const *s, unsigned int start);
int		get_nl_chr(char *str);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	carry_checker(char **carry, char *buff, t_args args);
int		ft_line_writer(int fd, char **line, t_args args, char **carry);

#endif
