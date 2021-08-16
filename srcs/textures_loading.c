#include "../include/textures_loading.h"

/*
**	Loads every needed xpm image file as a matrix of ints, each representing a
**	pixel.
*/

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

/*
**	Creates a temporary image to store the pixels of a xpm file, and after
**	saving its information on the matrix it destroys the image.
*/

int	**load_image_as_texture(t_vars *vars, char *path)
{
	t_temp	temp;
	int		x;
	int		y;
	int		**image;

	image = texture_init(vars);
	temp.img = mlx_xpm_file_to_image(vars->connection, path,
			  &temp.img_width, &temp.img_height);
	if (!temp.img)
		free_vars_and_exit(ERROR_READING_IMAGE_FILE, vars);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bits_per_pixel,
			   &temp.line_length, &temp.endian);
	y = -1;
	while (++y < temp.img_height)
	{
		x = -1;
		while (++x < temp.img_width)
		{
			image[y][x] = *(int *)(temp.addr
					+ (y * temp.line_length + (x * (temp.bits_per_pixel / 8))));
		}
	}
	mlx_destroy_image(vars->connection, temp.img);
	return (image);
}

/*
**	Initiates the matrices that are going to store the textures.
*/

int	**texture_init(t_vars *vars)
{
	int	i;
	int	**image;

	image = ft_calloc(HEIGHT, sizeof(int *));
	if (!image)
		free_vars_and_exit(FAILED_MALLOC, vars);
	i = 0;
	while (i < HEIGHT)
	{
		image[i] = ft_calloc(WIDTH, sizeof(int));
		if (!image[i])
		{
			ft_free_matrix(image, i);
			free_vars_and_exit(FAILED_MALLOC, vars);
		}
		i++;
	}
	return (image);
}

/*
**	Frees the textures. Gets called before terminating the program.
*/

void	free_textures(t_vars *vars)
{
	ft_free_matrix(vars->wall, HEIGHT);
	ft_free_matrix(vars->free_space, HEIGHT);
	ft_free_matrix(vars->exit, HEIGHT);
	ft_free_matrix(vars->enemy, HEIGHT);
	ft_free_matrix(vars->collectible, HEIGHT);
	ft_free_matrix(vars->player_right, HEIGHT);
	ft_free_matrix(vars->player_left, HEIGHT);
	ft_free_matrix(vars->end, HEIGHT);
}
