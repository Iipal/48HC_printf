void	ft_pf_out_valid(const char ch_act, va_list *argp)
{
	string d_str;

	if (ch_act == 'c')
		ft_putchar(va_arg(argp, int));
	else if (ch_act == 's')
		ft_putstr(va_arg(argp, const string));
	else if (ch_act == 'd')
		ft_putnbr(va_arg(argp, int));
	else if (ch_act == 'g')
	{
		if ((d_str = (string)malloc(sizeof(char) * 32 + 1)) != NULL)
		{
			ft_ftoa(va_arg(argp, double), d_str, 8);
			ft_putstr(d_str);
		}
		free(d_str);
	}
	else if (ch_act == '%')
		ft_putchar('%');
}

void	ft_pf_output(const string format, va_list *argp)
{
	ull		i;
	int		is_p;

	i = 0;
	while (format[i] != '\0')
	{
		is_p = 0;
		if (format[i] == '%')
		{
			is_p = 1;
			ft_pf_out_valid(format[i+1], argp);
			i += 2;
		}
		if (!is_p)
			ft_putchar(format[i++]);
	}
}

int		ft_printf(const string format, ...)
{
	va_list	argp;

	if (ft_strchr(format, '%') == NULL)
		ft_putstr((string)format); 
	else
	{
		va_start(argp, format);
		ft_pf_output(format, &argp);
		va_end(argp);
	}
}

int		main(void)
{
	double d = 12345678.12345678;
	ft_printf("empty va_\t\t\t| %c\n");
	ft_printf("test double percent flags\t| %%\n");
	ft_printf("only string without arg's\t| Hello, World!\n");
	ft_printf("test only c(\'!\')\t\t| Hello, World%c\n", '!');
	ft_printf("test only s(\"World!\")\t\t| Hello, %s\n", "World!");
	ft_printf("test c(\'W\') and s(\"orld\")\t| Hello, %c%s\n", 'W', "orld!");
	ft_printf("test only d(\'42\')\t\t| %d\n", 42);
	ft_printf("test only g(\'42.21\')\t\t| %g\n", 42.21);
	ft_printf("test double value \t\t| %g\n", d);
	ft_printf("test alot of d\t\t\t| %d-%d-%d-%d\n", 1, 2, 3, 4);
	ft_printf("My name is %s and i'm %d years old.\n", "Taras", 17);
}
