#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_putchar(int c);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_printf(const	char *str, ...);
int				ft_strlen(char *s);
int				ft_puthex(unsigned int nb, const char format);
int				check_flag(const char *str, int i, va_list ap);
int				ft_putchar_fd(char c, int fd);

#endif
