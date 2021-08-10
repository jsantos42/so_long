#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "main.h"

# define FD_SIZE 4096

int		get_next_line(int fd, char **line);
void	carry_checker(char **carry, char *buff, t_args args);
int		get_nl_chr(char *str);
int		ft_line_writer(int fd, char **line, t_args args, char **carry);
char	*ft_left_over(char const *s, unsigned int start);

#endif