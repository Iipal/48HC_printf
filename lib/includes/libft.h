#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // only for write
# include <stdlib.h> // for malloc, free and exit
# include <stdarg.h> // for all from this lib

typedef unsigned long long	ull;
typedef unsigned int		ui;
typedef char*				string;

void	ft_putchar(const char ch);
void	ft_putstr(const string str);
void	ft_putnbr(int nb);
void	ft_ftoa(double d, string dest, int after_point);

string	ft_strchr(const string dest, const char ch);

#endif
