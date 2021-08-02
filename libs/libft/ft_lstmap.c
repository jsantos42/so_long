#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_element;

	new_lst = 0;
	while (lst)
	{
		first_element = ft_lstnew(f(lst->content));
		if (!first_element)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, first_element);
		lst = lst->next;
	}
	return (new_lst);
}
