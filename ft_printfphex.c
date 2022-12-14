
#include "libft/libft.h"
#include "ft_printf.h"

/*  %p: includes 3 functions
		1) length 2)print en hexa 3) 2+1 et gerer les cas speciaux
*/

int	ft_lenhex(uintptr_t	nb)
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

void	ft_ptrhex(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_ptrhex(nb / 16);
		ft_ptrhex(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_pptrhex(unsigned long long nb)
{
	int	ptr;

	ptr = 0;
	if (nb == 0)
		return (write(1, "(nil)", 5));
	ptr += write(1, "0x", 2);
	ft_ptrhex(nb);
	ptr += ft_lenhex(nb);
	return (ptr);
}
