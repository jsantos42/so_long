#ifndef TEXTURES_H
# define TEXTURES_H

# include "main.h"

int		**load_image_as_texture(void *connection, char *path);
void	texture_init(int ***image);
void	print_image(int **texture, int start_x, int start_y, t_vars *vars);

#endif