#include "../include/init.h"

void	vars_init(t_vars **vars)
{
	*vars = malloc(sizeof(t_vars));
	if (!*vars)
		free_vars_and_exit(FAILED_MALLOC, *vars);
	(*vars)->connection = NULL;
	(*vars)->window = NULL;
	(*vars)->img = NULL;
	(*vars)->addr = NULL;
	(*vars)->map = NULL;
	(*vars)->wall = NULL;
	(*vars)->free_space = NULL;
	(*vars)->exit = NULL;
	(*vars)->enemy = NULL;
	(*vars)->collectible = NULL;
	(*vars)->player_right = NULL;
	(*vars)->player_left = NULL;
	(*vars)->end = NULL;
}

void	map_init(t_vars *vars)
{
	vars->map = malloc(sizeof(t_matrix));
	if (!vars->map)
		free_vars_and_exit(FAILED_MALLOC, vars);
	vars->map->matrix = NULL;
	vars->map->player_rotation = NULL;
}
