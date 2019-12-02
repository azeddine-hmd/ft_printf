#include "ft_printf.h"

int		ft_s_handler(va_list arglst, t_lilst *data)
{
	char	*arg;

	arg = va_arg(arglst, char*);
	data->string = ft_strdup("string");
	printf("ft_s_handler reached\n");
	arg++;
	return (1);
}
