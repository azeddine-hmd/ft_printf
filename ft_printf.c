#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	ft_putstr_fd((char*)s, 1);
	return (0);
}
