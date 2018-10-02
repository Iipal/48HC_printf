#include "../includes/libft.h"

char	*ft_strchr(const char *dest, const char ch)
{
	ull		i;

	i = 0;
	while (dest != NULL && dest[i] != '\0')
	{
		if (dest[i] == ch)
			return ((char *)(dest + i));
		i++;
	}
	return (NULL);
}
