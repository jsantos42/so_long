#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	iterator;

	if (lst != 0)
	{
		size = ft_lstsize(lst);
		iterator = 0;
		while (iterator++ < size - 1)
			lst = lst->next;
	}
	return (lst);
}
