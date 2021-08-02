#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		loc;
	size_t				i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	loc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i++] == loc)
			return (&d[i]);
	}
	return (0);
}
