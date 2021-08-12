#include "../../include/libft.h"

/*
**  pops/removes the top node of the stack (first element of the linked list)
**	and returns it.
**	NOTE1: we could protect the function to return 0 in case of an empty stack,
**	but 0 could be one of the numbers to sort, throwing an unexpected error;
**	as such, I'd rather check whether stack_size > 0 before calling stack_pop
**	NOTE2: in case we're not popping the last element, we make sure the new
**	top element's pointer to the previous element is set to NULL (line 22).
*/

int	stack_pop(t_stack **stack)
{
	t_stack	*temp;
	int		content;

	temp = (*stack)->next;
	content = (*stack)->content;
	free(*stack);
	*stack = temp;
	if (*stack)
		(*stack)->prev = NULL;
	return (content);
}
