#include "../includes/libft.h"

void	ft_strswap(string str, int len)
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

int		ft_strint(int x, string str, int d)
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

void	ft_ftoa(double d, string dest, int after_point)
{
	int		i_part;
	float	d_part;
	int		i;

	i_part = (int)d;
	d_part = d - (double)i_part;
	i = ft_strint(i_part, dest, 0);
	if (after_point != 0)
	{
		dest[i] = '.';
		d_part *= ft_pow(10, after_point);
		ft_strint((int)d_part, dest + i + 1, after_point);
	}
}
