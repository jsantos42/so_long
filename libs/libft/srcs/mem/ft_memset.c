#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;
	size_t			i;

	string = b;
	i = 0;
	while (i < len)
		string[i++] = c;
	return (b);
}
