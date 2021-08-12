#include "libft.h"

/*
**	Deletes the string passed as a parameter. If first sets its memory bytes to
**	zero, and then frees its memory.
**
**	NOTE: the str parameter is of type void* so that this function can be used
**	with the ft_lstdelone function of this library.
*/

void	ft_str_eraser(void *str)
{
	ft_bzero(str, (int)ft_strlen(str));
	free(str);
}
