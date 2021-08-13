#ifndef MAIN_H
# define MAIN_H

# include "../libs/minilibx_mms_20200219/mlx.h"
# include "../libs/libft/include/libft.h"
# include <fcntl.h>
//# include <stdlib.h>
//# include <unistd.h>

/*
**	Here types.h must come first since it has the defines and typedefs.
*/

# include "types.h"
# include "1_error_management.h"
# include "4_get_next_line.h"
# include "8_hooks.h"
# include "2_map_checking.h"
# include "3_map_importing.h"
# include "6_map_printing.h"
# include "9_player.h"
# include "7_put_to_window_img.h"
# include "5_textures_loading.h"

/*
**	X11 Events
*/

# define DESTROY_NOTIFY	17

void	img_init(t_vars *vars);

#endif
