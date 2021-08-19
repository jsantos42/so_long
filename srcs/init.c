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
	vars->map->lines = 0;
	vars->map->columns = 0;
	vars->map->matrix = NULL;
	vars->map->player_rotation = NULL;
}

void	win_img_init(t_vars *vars)
{
	vars->window_width = vars->map->columns * WIDTH;
	vars->window_height = vars->map->lines * HEIGHT;
	vars->window = mlx_new_window(vars->connection, vars->window_width,
			  vars->window_height, "SO LONG" );
	if (!vars->window)
		free_vars_and_exit(NO_WINDOW, vars);
	vars->img = mlx_new_image(vars->connection, vars->window_width,
			  vars->window_height);
	if (!vars->img)
		free_vars_and_exit(NO_IMG, vars);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			   &vars->line_length, &vars->endian);
}
