#include "ft_printf.h"

int		ft_s_handler(va_list arglst, t_lilst *data)
{
	char	*arg;

	arg = va_arg(arglst, char*);
	data->flags = ft_strdup("flags");
	printf("ft_s_handler reached\n");
	return (1);
}
