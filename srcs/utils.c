#include "../include/main.h"

void	erase_str(void *str)
{
	ft_bzero(str, (int)ft_strlen(str));
	free(str);
}
