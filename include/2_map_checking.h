#ifndef MAP_CHECKING_H
# define MAP_CHECKING_H

# include "0_main.h"

int	check_map_criteria(t_matrix *map);
int	find_char_in_map(t_matrix *map, char letter);
int	check_map_walls(t_matrix *map);

#endif