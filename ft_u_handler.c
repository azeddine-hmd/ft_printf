#include "ft_printf.h"

int		ft_u_handler(va_list arglst, t_lilst *data)
{
	unsigned int	arg;

	arg = va_arg(arglst, unsigned int);
	data->flags = ft_strdup("flags");
	printf("ft_u_handler reached\n");
	return (1);
}
