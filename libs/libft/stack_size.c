#include "libft.h"

/*
**	determines the number of elements on the stack
*/

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size += 1;
		stack = stack->next;
	}
	return (size);
}
