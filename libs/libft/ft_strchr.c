#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	loc;
	int		i;

	loc = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == loc)
			break ;
		else
			i++;
	}
	if (s[i] == '\0' && loc != '\0')
		return (0);
	else
		return (&((char *)s)[i]);
}
