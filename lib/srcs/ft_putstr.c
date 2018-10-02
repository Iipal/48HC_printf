#include "../includes/libft.h"

void	ft_putstr(const string str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
