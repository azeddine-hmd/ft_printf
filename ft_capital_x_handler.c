#include "ft_printf.h"

int		ft_capital_x_handler(va_list arglst, t_lilst *data)
{
	char	arg;

	arg = va_arg(arglst, int);
	data->flags = ft_strdup("flags");
	printf("ft_capital_x_handler reached\n");
	return (1);
}
