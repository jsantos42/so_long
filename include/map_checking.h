#ifndef MAP_CHECKING_H
# define MAP_CHECKING_H

# include "main.h"

int	check_map_criteria(t_map *map);
int	find_char_in_map(t_map *map, char letter);
int	check_map_walls(t_map *map);

#endif