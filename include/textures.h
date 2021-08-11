#ifndef TEXTURES_H
# define TEXTURES_H

# include "main.h"

int		**load_image_as_texture(void *connection, char *path);
void	texture_init(int ***image);

#endif