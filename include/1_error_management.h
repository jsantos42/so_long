#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# include "0_main.h"

/*
**	ERRORS
*/

# define ILLEGAL_INPUT		1
# define FAILED_MALLOC		2
# define WRONG_EXTENSION	3
# define ERROR_READING_MAP_FILE	4
# define INVALID_MAP		5
# define ERROR_READING_IMAGE_FILE 6

void	error_management(int error);
void	free_list_and_exit(int error, t_list *line_list);
void	free_matrix_and_exit(int error, t_matrix *map);

#endif