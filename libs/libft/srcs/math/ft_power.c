#include "../../include/libft.h"

double	ft_power(double base, double exp)
{
	if (exp == 0)
		return (1);
	if (exp > 0)
		return (base * ft_power(base, exp - 1));
	else
	{
		base = 1 / base;
		exp *= -1;
		return (base * ft_power(base, exp - 1));
	}
}
