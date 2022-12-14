
#include "ft_printf.h"


int ft_printf(const char *format, ...)
{
	va_list ap; /* pointer */
	int count;
	int i;

	i = 0;
	count = 0;
	va_start (ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += check_flag(format, i, ap);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

int	check_flag(const char *str, int i, va_list ap)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar((va_arg(ap, int)));
	else if (str[i] == 's')
		count += ft_putstr((va_arg(ap, char*)));
/*
	else if (str[i] == 'p')
		count += ft_put_hex(ap);
*/
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'u')
		count += ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'x')
		count += ft_puthex(va_arg(ap, int), str[i]);
	else if (str[i] == 'X')
		count += ft_puthex(va_arg(ap, int), str[i]);
	else if (str[i] == '%')
	{
		write (1, "%", 1);
		count = 1;
	}
	return (count);
}

int	main(void)
{
	/*ft_printf("The color: %s\n", "blue");*/
	ft_printf("First number: %d\n", 12345);
	ft_printf("Hexadecimal: %x\n", 255);
}
