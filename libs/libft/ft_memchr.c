#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	loc;

	string = (unsigned char *) s;
	loc = (unsigned char)c;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*string == loc)
			return (string);
		string++;
		n--;
	}
	return (0);
}
