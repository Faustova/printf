
#include "ft_printf.h"

/*
prints in hex in M or M

	count character
	write them out
	return the output and the number of characters (0X0)
*/

int	ft_lenh(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_ptrh(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_ptrh(nb / 16, format);
		ft_ptrh(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_puthex(unsigned int nb, const char format)
{
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	ft_ptrh(nb, format);
	return (ft_lenh(nb));
}
