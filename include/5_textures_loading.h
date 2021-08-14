#ifndef TEXTURES_LOADING_H
# define TEXTURES_LOADING_H

# include "0_main.h"

void	load_textures(t_vars *vars);
int		**load_image_as_texture(t_vars *vars, char *path);
int		**texture_init(t_vars *vars);
void	free_matrix(int **matrix, int number_of_arrays);
void	free_textures(t_vars *vars);

#endif