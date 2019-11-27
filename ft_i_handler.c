#include "ft_printf.h"

int		ft_i_handler(va_list arglst, t_lilst *data)
{
	int		i;

	i = va_arg(arglst, int);
	data->flags = ft_strdup("flags");
	printf("i_handler reached\n");
	return (1);
}
