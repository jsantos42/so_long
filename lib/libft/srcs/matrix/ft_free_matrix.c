#include "../../include/libft.h"

/*
**	This function is called to free the various arrays of a matrix. One possible
**	use could be to free the already allocated arrays of a matrix when there's
**	an error and the program must quit.
**	Parameters:
**	1) The matrix itself.
**	2) The number of arrays on it.
*/

void	ft_free_matrix(int **matrix, int arrays)
{
	int	iter;

	if (matrix)
	{
		iter = 0;
		while (iter < arrays)
			free(matrix[iter++]);
		free(matrix);
	}
}
