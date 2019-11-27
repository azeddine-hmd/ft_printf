#include "ft_printf.h"

int		P_handler(va_list arglst, t_lilst *data)
{
	printf("%%_handler reached\n");
	return (1);
}
