#include "ft_printf.h"

int		ft_x_handler(va_list arglst, t_lilst *data)
{
	unsigned int	i;

	arg = va_arg(arglst, unsigned int);
	data-flags = ft_strdup("flags");
	printf("x_handler reached\n");
	return (1);
}
