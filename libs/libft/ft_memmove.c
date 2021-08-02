#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else if (s > d)
		ft_memcpy(d, s, len);
	return (d);
}
