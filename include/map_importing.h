#ifndef MAP_IMPORTING_H
# define MAP_IMPORTING_H

#include "main.h"

int			check_map_extension(char *str);
t_matrix	*import_map(char *str);
t_list		*map_lines_to_linked_list(int fd, int *line_count, int *line_length);
char		**linked_list_to_matrix(t_list *line_list, size_t line_count);
void		import_player_xy_and_collectible_count(t_vars *vars);

#endif