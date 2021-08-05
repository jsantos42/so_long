#include "get_next_line.h"

#define FD_SIZE 4096

int	get_next_line(int fd, char **line)
{
	t_args		args;
	char		buff[BUFFER_SIZE + 1];
	static char	*carry[FD_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	args.reading = read(fd, buff, BUFFER_SIZE);
	while (args.reading)
	{
		if (args.reading == -1)
			return (-1);
		buff[args.reading] = '\0';
		carry_checker(&carry[fd], buff, args);
		if (carry[fd] != NULL)
			args.nl_index = get_nl_chr(carry[fd]);
		if (args.nl_index >= 0)
			break ;
		args.reading = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_line_writer(fd, line, args, carry));
}

void	carry_checker(char **carry, char *buff, t_args args)
{
	if (*carry == NULL)
		*carry = ft_strdup(buff);
	else
	{
		args.temp = ft_strjoin(*carry, buff);
		free(*carry);
		*carry = args.temp;
	}
}

int	get_nl_chr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

int	ft_line_writer(int fd, char **line, t_args args, char **carry)
{
	if (args.reading == 0 && carry[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	args.nl_index = get_nl_chr(carry[fd]);
	if (args.nl_index >= 0)
	{
		*line = ft_substr(carry[fd], 0, args.nl_index);
		args.temp = ft_left_over(carry[fd], args.nl_index + 1);
		free(carry[fd]);
		carry[fd] = args.temp;
		return (1);
	}
	else
	{
		*line = ft_left_over(carry[fd], 0);
		free(carry[fd]);
		carry[fd] = NULL;
		return (0);
	}
}

char	*ft_left_over(char const *s, unsigned int start)
{
	char	*sub;
	size_t	size;
	size_t	iter;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size)
		size = 0;
	sub = (char *) malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	iter = 0;
	if (size != 0)
		while (s[start] != 0)
			sub[iter++] = s[start++];
	sub[iter] = '\0';
	return (sub);
}
