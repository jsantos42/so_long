#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		size;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, size);
	return (s2);
}
