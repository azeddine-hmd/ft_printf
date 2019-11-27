#include "ft_printf.h"

int		c_handler(va_list arglst, t_lilst *data)
{
	printf("c_handler reached\n");
	va_arg(arglst, int);
	data->flags = ft_strdup("flags");
	return (1);
}
