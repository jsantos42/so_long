#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (string1[i] == string2[i])
			i++;
		else
			return (string1[i] - string2[i]);
	}
	if (string1[i] == string2[i])
		return (0);
	else
		return (string1[i] - string2[i]);
}
