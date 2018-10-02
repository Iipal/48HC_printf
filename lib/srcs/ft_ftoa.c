#include "../includes/libft.h"

void	ft_strswap(char *str, int len)
{
	int	i;
	int j;
	int tmp;

	i = 0;
	j = len - 1;
	tmp = 0;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int		ft_strint(int x, char str[], int d)
{
	int	i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i < d)
		str[i++] = '0';
	ft_strswap(str, i);
	str[i] = '\0';
	return (i);
}

int		ft_pow(int x, ui y)
{
	int	tmp;

	if (y == 0)
		return (1);
	tmp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (tmp * tmp);
	else
		return (x * tmp * tmp);
}

void	ft_ftoa(float f, char *dest, int ap)
{
	int		i_p;
	float	f_p;
	int		i;

	i_p = (int)f;
	f_p = f - (float)i_p;
	i = ft_strint(i_p, dest, 0);
	if (ap != 0)
	{
		dest[i] = '.';
		f_p = f_p * ft_pow(10, ap);
		ft_strint((int)f_p, dest + i + 1, ap);
	}
}
