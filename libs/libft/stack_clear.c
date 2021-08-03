#include "libft.h"

/*
**	deletes (and frees the allocated memory) the given stack
*/

void	stack_clear(t_stack *stack)
{
	t_stack	*temp;

	while(stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}