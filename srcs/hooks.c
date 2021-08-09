#include "../include/main.h"

int on_key_press(int key, t_vars *vars)
{
	if (key == ESC)
	{
		//mlx_destroy_window needed??
		free_matrix_and_exit(0, vars->map);
	}
	else if (key == 126)
	{
		vars->map->matrix[2][1] = 'P'; //function to switch values if zero
		print_map(vars);
		mlx_put_image_to_window(vars->connection, vars->window, vars->img, 0, 0);
	}
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	on_click(int button, int x, int y, void *param)
{
	(void)param;

	ft_putnbr_fd(button, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(y, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

/*
**	This function is called when the user clicks the red cross button to close
**	the window. When doing so, it activates an X11 event called DESTROY_NOTIFY
**	and represented by an integer of value 17.
**	It's important to free all the allocated memory before terminating the
**	program. In this case, since it is no error, it gives 0 as an argument.
*/

int red_cross_clicking(t_matrix *map)
{
	//mlx_destroy_window needed??
	free_matrix_and_exit(0, map);
	return (0);
}
