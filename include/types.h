#ifndef TYPES_H
# define TYPES_H

# define IMG_HEIGHT 50
# define IMG_WIDTH	50

# define NUMBER_OF_ENEMIES	2


typedef struct s_matrix {
	char	**matrix;
	int 	lines;
	int		columns;
	int 	player_coord_x;
	int 	player_coord_y;
	int		**player_current_rotation;
	int 	enemy_coord_x[NUMBER_OF_ENEMIES];
	int 	enemy_coord_y[NUMBER_OF_ENEMIES];
	int 	collectible_count;
	int 	moves_count;
	int 	end_of_game;
	int 	text_x;
	int 	text_y;
	int 	text_color;
}	t_matrix;

/*
**	Due to the limitations of the MiniLibX, which has some functions (namely,
**	the hook ones) to which we can only pass a single argument, the following
**	structure has quite a bit of elements inside of it. The first ones are
**	related to the connection established by the MiniLibX and its data.
**	After that, there's a map variable which saves the map passed as an argument
**	to the program, followed by the textures used on this program.
*/

typedef struct s_vars {
	void 		*connection;
	void		*window;
	void		*img;
	char		*addr;
	int 		bits_per_pixel;
	int 		line_length;
	int 		endian;
	int 		window_height;
	int			window_width;
	t_matrix	*map;
	int 		**wall;
	int 		**free_space;
	int 		**exit;
	int 		**enemy;
	int 		**collectible;
	int 		**player_right;
	int 		**player_left;
	int 		**end;
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

typedef struct s_enemies {
	int	x;
	int	y;
	int	enemy_i;
	int	space_between_enemies;
	int	space_i;
}	t_enemies;

/*
** GNL stuff
*/

#define BUFFER_SIZE 2

typedef struct s_args
{
	int		reading;
	char	*temp;
	int		nl_index;
}	t_args;

#endif
