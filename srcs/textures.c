#include "../include/textures.h"

int	**load_image_as_texture(void *connection, char *path)
{
	t_temp	temp;
	int		x;
	int		y;
	int	**image;

	texture_init(&image);
	temp.img = mlx_xpm_file_to_image(connection, path, &temp.img_width, &temp.img_height);
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
	//free temp?
	return (image);
}


void	texture_init(int ***image)
{
	int	i;

	*image = ft_calloc(IMG_HEIGHT, sizeof(int*));
	///protect against calloc
	i = 0;
	while (i < IMG_HEIGHT)
	{
		(*image)[i] = ft_calloc(IMG_WIDTH,sizeof (int));
		i++;
	}
}


