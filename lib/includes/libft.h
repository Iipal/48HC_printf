#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // only for write
# include <stdlib.h> // for malloc, free and exit
# include <stdarg.h> // for all from this lib

typedef unsigned long long	ull;
typedef unsigned int		ui;

void	ft_putchar(const char ch);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	ft_ftoa(float f, char *dest, int ap);

char	*ft_strchr(const char *dest, const char ch);

#endif
