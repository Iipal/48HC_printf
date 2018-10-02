#include <stdio.h>
#include <math.h>

void	ft_pf_output(const char *format, va_list *argp)
{
	ull		i;
	int		is_p;
	char	*d;

	i = 0;
	while (format[i] != '\0')
	{
		is_p = 0;
		if (format[i] == '%')
		{
			is_p = 1;
			if (format[i + 1] == 'c')
				ft_putchar(va_arg(argp, int));
			if (format[i + 1] == 's')
				ft_putstr(va_arg(argp, const char*));
			if (format[i + 1] == 'd')
				ft_putnbr(va_arg(argp, int));
			if (format[i + 1] == 'g')
			{
				d = (char *)malloc(sizeof(char) * 4 + 1);
				ft_ftoa(va_arg(argp, double), d, 4);
				ft_putstr(d);
			}
			i += 2;
		}
		if (!is_p)
			ft_putchar(format[i++]);
	}

}
int		ft_printf(const char *format, ...)
{
	va_list	argp;

	va_start(argp, format);
	if (ft_strchr(format, '%') == NULL)
		ft_putstr((char *)format); 
	else
		ft_pf_output(format, &argp);
	va_end(argp);
}

int		main(void)
{
	ft_printf("only string without arg's\t| Hello, World!\n");
	ft_printf("test only c(\'!\')\t\t| Hello, World%c\n", '!');

	ft_printf("test only s(\'World!\')\t\t| Hello, %s\n", "World!");
	ft_printf("test c(\'W\') and s(\"orld\")\t| Hello, %c%s\n", 'W', "orld!");
	ft_printf("test only d(\'42\')\t\t| %d\n", 42);
	ft_printf("test only g(\'42.21\')\t\t| %g\n", 42.21);
	ft_printf("test only g(\'54.0034\')\t\t| %g\n", 54.0034);
}
