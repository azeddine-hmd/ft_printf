#include "ft_printf.h"

int		ft_u_handler(va_list arglst, t_lilst *data)
{
	printf("u_handler reached\n");
	va_arg(arglst, unsigned int);
	data->flags = ft_strdup("flags");
	return (1);
}
