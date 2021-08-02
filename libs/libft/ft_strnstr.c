#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	iter_h;
	size_t	iter_n;
	size_t	flag;

	flag = 0;
	iter_h = 0;
	iter_n = 0;
	while (iter_h < len && haystack[iter_h] != '\0' && needle[iter_n] != '\0')
	{
		if (haystack[iter_h++] == needle[iter_n])
		{
			iter_n++;
			if (flag == 0)
				flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;
			iter_h -= iter_n;
			iter_n = 0;
		}
	}
	if (needle[iter_n] == '\0')
		return (&((char *)haystack)[iter_h - iter_n]);
	return (0);
}
