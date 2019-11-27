#include "ft_printf.h"

int		c_handler(va_list arglst, t_lilst *data)
{
	char	arg;

	arg = va_arg(arglst, int);
	data->flags = ft_strdup("flags");
	printf("c_handler reached\n");
	return (1);
}
