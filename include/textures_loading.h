#ifndef TEXTURES_LOADING_H
# define TEXTURES_LOADING_H

# include "main.h"

void	load_textures(t_vars *vars);
int		**load_image_as_texture(t_vars *vars, char *path);
int		**texture_init(t_vars *vars);

#endif