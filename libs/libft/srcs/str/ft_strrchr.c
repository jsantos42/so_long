#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	char	loc;
	int		len;

	string = (char *)s;
	loc = (char)c;
	len = ft_strlen(string);
	string += len;
	if (loc == '\0')
		return (string);
	while (len > 0)
	{
		if (*(--string) == loc)
			return (string);
		len--;
	}
	return (0);
}
