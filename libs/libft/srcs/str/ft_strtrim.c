#include "libft.h"

static int	get_begin(const char *s1, const char *set)
{
	int	begin;
	int	iterator;

	begin = 0;
	iterator = 0;
	while (s1[begin] != '\0' && set[iterator] != '\0')
	{
		if (s1[begin] == set[iterator++])
		{
			begin++;
			iterator = 0;
		}
	}
	return (begin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	char	*temp;
	int		iterator;
	int		begin;
	int		end;

	if (!s1)
		return (0);
	temp = (char *)s1;
	iterator = 0;
	begin = get_begin(s1, set);
	end = ft_strlen(s1) - 1;
	while (end >= 0 && set[iterator] != '\0')
	{
		if (s1[end] == set[iterator++])
		{
			end--;
			iterator = 0;
		}
	}
	temp += begin;
	trimmed = ft_substr(temp, 0, end - begin + 1);
	return (trimmed);
}
