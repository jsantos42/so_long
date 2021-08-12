#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*reserved;

	reserved = malloc(size * count);
	if (!reserved)
		return (0);
	ft_bzero(reserved, size * count);
	return (reserved);
}
