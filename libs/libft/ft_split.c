#include "libft.h"

static size_t	ft_strcounter(const char *s1, char splitter)
{
	size_t	flag;
	size_t	strings;

	flag = 0;
	strings = 0;
	while (*s1)
	{
		if (*s1 != splitter && flag == 0)
		{
			strings += 1;
			flag = 1;
		}
		else if (*s1 == splitter)
			flag = 0;
		s1++;
	}
	return (strings);
}

static size_t	get_end_index(const char *str, char stop)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != stop)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		n_strings;
	int		string_i;
	int		end;

	if (!s)
		return (0);
	n_strings = ft_strcounter(s, c);
	array = (char **)malloc(sizeof(char *) * (n_strings + 1));
	if (!array)
		return (0);
	string_i = 0;
	while (string_i < n_strings && *s)
	{
		if (*s == c)
			s++;
		else
		{
			end = get_end_index(s, c);
			array[string_i++] = ft_substr(s, 0, end);
			s += end;
		}
	}
	array[string_i] = 0;
	return (array);
}
