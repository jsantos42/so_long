#ifndef TEXTURES_LOADING_H
# define TEXTURES_LOADING_H

# include "0_main.h"

int		**load_image_as_texture(void *connection, char *path);
void	texture_init(int ***image);

#endif