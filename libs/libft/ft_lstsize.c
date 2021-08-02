#include "libft.h"

/*
** If you're trying to calculate the number of elements of the keys array
** you can simply do sizeof(keys)/sizeof(keys[0]).
** The point is that the
** result of sizeof(keys) is the size in bytes of the keys array in memory.
** This is not the same as the number of elements of the array, unless the
** elements are 1 byte long. To get the number of elements you need to divide
** the number of bytes by the size of the element type which is
** sizeof(keys[0]), which will return the size of the datatype of key[0].
**
** in https://stackoverflow.com/questions/4275921/
** getting-the-number-of-elements-in-a-struct
*/

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst != 0)
	{
		while (lst)
		{
			lst = lst->next;
			size++;
		}
	}
	return (size);
}
