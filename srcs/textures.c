#include "../include/main.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	**load_image_as_texture(void *connection, char *path)
{
	t_temp	temp;
	int		x;
	int		y;
	int	**image;

	texture_init(&image);
	printf("%s\n", strerror(errno));
	temp.img = mlx_xpm_file_to_image(connection, path, &temp.img_width, &temp.img_height);
	printf("%s\n", strerror(errno));
//	exit(0);
	if (!temp.img)
		error_management(ERROR_READING_IMAGE_FILE);
	//what do I have to free here??
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
	mlx_destroy_image(connection, temp.img);
	return (image);
}


void	texture_init(int ***image)
{
	int	i;

	*image = ft_calloc(IMG_HEIGHT, sizeof(int*));
	i = 0;
	while (i < IMG_HEIGHT)
	{
		(*image)[i] = ft_calloc(IMG_WIDTH,sizeof (int));
//		for (int j = 0; j < IMG_WIDTH; j++)
//			printf("%d", (*image)[i][j]);
//		printf("\n");
		i++;
	}
}


void	print_image(int **texture, int starting_x, int starting_y, t_vars *vars)
{
	int x;
	int y;

	y = starting_y;
	while (y <  starting_y + IMG_HEIGHT)
	{
		x = starting_x;
		while (x < starting_x + IMG_WIDTH)
		{
			my_pixel_put(vars, x, y, texture[y - starting_y][x - starting_x]);
			my_pixel_put(vars, 2 * x, 2 * y, texture[y - starting_y][x - starting_x]);
			my_pixel_put(vars, (2 * x) - 1, (2 * y) - 1, texture[y - starting_y][x - starting_x]);
			my_pixel_put(vars, (2 * x) - 1, (2 * y), texture[y - starting_y][x - starting_x]);
			my_pixel_put(vars, (2 * x), (2 * y) - 1, texture[y - starting_y][x - starting_x]);
			x++;
		}
		y++;
	}
}


//void	my_pixel_put(t_vars *vars, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = vars->addr + (y * vars->line_length + (x * (vars->bits_per_pixel / 8)));
//	*(int *)dst = color;
//}
