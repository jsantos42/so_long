#ifndef MAIN_H
# define MAIN_H

# include "../libs/minilibx_mms_20200219/mlx.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
//# include <stdlib.h>
//# include <unistd.h>

# include "types.h"
# include "print_shapes.h"
# include "colors.h"
# include "gradients.h"
# include "hooks.h"
# include "error_management.h"
# include "map_importing.h"
# include "get_next_line.h"
# include "utils.h"
# include "map_checking.h"
# include "textures.h"
# include "move_player.h"
# include "map_printing.h"


void	img_init(t_vars *vars);
t_color	colors_init(int starting_x, int starting_y, int first_color, int second_color);

#endif
