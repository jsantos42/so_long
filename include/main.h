#ifndef MAIN_H
# define MAIN_H

# include "../libs/minilibx_mms_20200219/mlx.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
//# include <stdlib.h>
//# include <unistd.h>

/*
**	Here types.h must come first since it has the defines and typedefs.
*/

# include "types.h"
# include "colors.h"
# include "error_management.h"
# include "get_next_line.h"
# include "gradients.h"
# include "hooks.h"
# include "map_checking.h"
# include "map_importing.h"
# include "map_printing.h"
# include "move_player.h"
# include "print_shapes.h"
# include "put_to_window_img.h"
# include "textures.h"
# include "utils.h"


void	img_init(t_vars *vars);
t_color	colors_init(int starting_x, int starting_y, int first_color, int second_color);

#endif
