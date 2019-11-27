#include "ft_printf.h"

int		s_handler(va_list arglst, t_lilst *data)
{
	printf("s_handler reached\n");
	return (1);
}
