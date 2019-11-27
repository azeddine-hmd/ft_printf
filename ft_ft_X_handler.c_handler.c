#include "ft_printf.h"

int		X_handler(va_list arglst, t_lilst *data)
{
	printf("X_handler reached\n");
	return (1);
}
