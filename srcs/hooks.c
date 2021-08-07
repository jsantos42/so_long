#include "../include/main.h"

int on_key_press(int key, t_matrix *map)
{
	if (key == 53)
		free_matrix_and_exit(0, map);
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	on_click(int key, void *param)
{
	(void)param;
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
