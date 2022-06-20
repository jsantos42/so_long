#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include "../lib/libft/include/libft.h"
# include <fcntl.h>

/*
**	Here types.h must come first since it has the defines and typedefs.
*/

# include "types.h"
# include "enemies_initial_setup.h"
# include "enemies_movement.h"
# include "error_and_free.h"
# include "get_next_line.h"
# include "hooks.h"
# include "init.h"
# include "map_checking.h"
# include "map_importing.h"
# include "map_printing.h"
# include "player.h"
# include "put_to_window_img.h"
# include "textures_loading.h"

/*
**	X11 Events
*/

# define DESTROY_NOTIFY	17

#endif
