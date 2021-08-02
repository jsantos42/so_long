#include "libft.h"

/*
**  On L29 we test whether the given list is empty (the star is crucial, since
**  otherwise we would be testing whether the pointer to the list is NULL,
**  which isn't, it just points to a empty list). Other way to do it would be:
**	if (last != 0)
**		last->next = new;
**	else
**		*lst = new;
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst != 0)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
