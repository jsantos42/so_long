#include "../include/textures_loading.h"

void	load_textures(t_vars *vars)
{
	vars->wall = load_image_as_texture(vars, "imgs/wall.xpm");
	vars->free_space = load_image_as_texture(vars, "imgs/free_space.xpm");
	vars->exit = load_image_as_texture(vars, "imgs/exit.xpm");
	vars->enemy = load_image_as_texture(vars, "imgs/enemy.xpm");
	vars->collectible = load_image_as_texture(vars, "imgs/collectible.xpm");
	vars->player_right = load_image_as_texture(vars, "imgs/player_right.xpm");
	vars->player_left = load_image_as_texture(vars, "imgs/player_left.xpm");
	vars->end = load_image_as_texture(vars, "imgs/end.xpm");
}

int	**load_image_as_texture(t_vars *vars, char *path)
{
	t_temp	temp;
	int		x;
	int		y;
	int		**image;

	image = texture_init(vars);
	temp.img = mlx_xpm_file_to_image(vars->connection, path, &temp.img_width, &temp.img_height);
	if (!temp.img)
		free_vars_and_exit(ERROR_READING_IMAGE_FILE, vars);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bits_per_pixel, &temp.line_length, &temp.endian);
	y = 0;
	while (y < temp.img_height)
	{
		x = 0;
		while (x < temp.img_width)
		{
			image[y][x] = *(int*)(temp.addr + (y * temp.line_length + (x * (temp.bits_per_pixel / 8))));
			x++;
		}
		y++;
	}
	mlx_destroy_image(vars->connection, temp.img);
	return (image);
}


int	**texture_init(t_vars *vars)
{
	int	i;
	int	**image;

	image = ft_calloc(IMG_HEIGHT, sizeof(int*));
	if (!image)
		free_vars_and_exit(FAILED_MALLOC, vars);
	i = 0;
	while (i < IMG_HEIGHT)
	{
		image[i] = ft_calloc(IMG_WIDTH, sizeof(int));
		if (!image[i])
		{
			ft_free_matrix(image, i);
			free_vars_and_exit(FAILED_MALLOC, vars);
		}
		i++;
	}
	return (image);
}

void	free_textures(t_vars *vars)
{
	ft_free_matrix(vars->wall, IMG_HEIGHT);
	ft_free_matrix(vars->free_space, IMG_HEIGHT);
	ft_free_matrix(vars->exit, IMG_HEIGHT);
	ft_free_matrix(vars->enemy, IMG_HEIGHT);
	ft_free_matrix(vars->collectible, IMG_HEIGHT);
	ft_free_matrix(vars->player_right, IMG_HEIGHT);
	ft_free_matrix(vars->player_left, IMG_HEIGHT);
	ft_free_matrix(vars->end, IMG_HEIGHT);
}
