#ifndef MAP_IMPORTING_H
# define MAP_IMPORTING_H

# include "main.h"

int			check_map_extension(char *str);
void		*import_map(char *str, t_vars *vars);
t_list		*map_to_linked_list(int fd, int *lines, int *columns, t_vars *vars);
char		**linked_list_to_matrix(t_list *line_list, int lines, t_vars *vars);
void		set_map_parameters(t_matrix *map);

#endif