#include "ft_printf.h"

int		ft_d_handler(va_list arglst, t_lilst *data)
{
	int		arg;

	arg = va_arg(arglst, int);
	data->flags = ft_strdup("flags");
	printf("ft_d_handler reached\n");
	return (1);
}
