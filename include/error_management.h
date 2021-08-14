#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# include "main.h"

/*
**	ERRORS
*/

# define ILLEGAL_INPUT				1
# define FAILED_MALLOC				2
# define WRONG_EXTENSION			3
# define ERROR_READING_MAP_FILE		4
# define INVALID_MAP				5
# define ERROR_READING_IMAGE_FILE	6
# define NO_CONNECTION				7
# define NO_WINDOW					8
# define NO_IMG						9

void	error_management(int error);
void	*free_list(t_list *line_list);
void	free_vars_and_exit(int error, t_vars *vars);

#endif