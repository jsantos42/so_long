#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	iter;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size)
		size = 0;
	if (size > len)
		size = len;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	iter = 0;
	if (size != 0)
		while (iter < len && s[start] != 0)
			sub[iter++] = s[start++];
	sub[iter] = '\0';
	return (sub);
}
