#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*output;

	if (!(s && f))
		return (0);
	len = ft_strlen(s);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (0);
	len = -1;
	while (s[++len])
		output[len] = f(len, s[len]);
	output[len] = 0;
	return (output);
}
