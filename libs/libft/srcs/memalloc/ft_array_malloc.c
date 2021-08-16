#include "../../include/libft.h"

int	ft_array_malloc(int *array, int size)
{
	array = malloc(sizeof(int) * size);
	if (!array)
		return (0);
	else
		return (1);
}
