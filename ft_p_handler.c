#include "ft_printf.h"

int		ft_p_handler(va_list arglst, t_lilst *data)
{
	void	*arg;

	arg = va_arg(arglst, void*);
	data->string = ft_strdup("string");
	printf("ft_p_handler reached\n");
	arg++;
	return (1);
}
