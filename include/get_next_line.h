#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 2

typedef struct s_args
{
	int		reading;
	char	*temp;
	int		nl_index;
}	t_args;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_left_over(char const *s, unsigned int start);
int		get_nl_chr(char *str);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	carry_checker(char **carry, char *buff, t_args args);
int		ft_line_writer(int fd, char **line, t_args args, char **carry);

#endif
