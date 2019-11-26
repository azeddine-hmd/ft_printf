#include "ft_printf.h"
#include <stdio.h>

int		c_handler(va_list arglst, t_lilst *data)
{
	printf("c_handler() excuted");
	va_arg(arglst, int);
	data->string = "lol";
	return (1);
}
