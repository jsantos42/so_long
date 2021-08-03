#include "libft.h"

/*
** creates a new stack node
** Note: the malloc is for the t_stack type, so that it allocates enough
** memory for every variable inside the struct. Do not malloc just for the
** pointer to the structure (stack) neither for the stack->content.
*/

t_stack	*stack_new(int new_content)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->content = new_content;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}
