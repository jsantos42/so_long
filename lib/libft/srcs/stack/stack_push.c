#include "../../include/libft.h"

/*
**  pushes/inserts a new node at the top of the stack (head of the linked list)
**	Note: on linked lists, the pointers next and prev should point to the next
**	element itself (in this case, *stack, since this argument is passed by
**	reference), not to its content (stack->content)
*/

void	stack_push(t_stack **stack, int new_content)
{
	t_stack	*new_node;

	if (*stack != NULL)
	{
		new_node = stack_new(new_content);
		new_node->next = *stack;
		(*stack)->prev = new_node;
		(*stack) = new_node;
	}
	else
		*stack = stack_new(new_content);
}
