#include "../../include/libft.h"

/*
**	Returns the absolute value of the given number.
*/

int	ft_abs(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}
