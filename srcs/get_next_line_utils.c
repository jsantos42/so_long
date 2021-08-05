#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	if (d != s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		size;

	size = ft_strlen(s1) + 1;
	s2 = (char *) malloc(size);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, size);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc((len + 1));
	if (!joined)
		return (0);
	i = 0;
	j = 0;
	while (i < len && s1[j] != 0)
		joined[i++] = s1[j++];
	j = 0;
	while (i < len && s2[j] != 0)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

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
	sub = (char *) malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	iter = 0;
	if (size != 0)
		while (iter < len && s[start] != 0)
			sub[iter++] = s[start++];
	sub[iter] = '\0';
	return (sub);
}
