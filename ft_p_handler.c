#include "ft_printf.h"

int		ft_p_handler(va_list arglst, t_lilst *data)
{
	void	*arg;

	arg = va_arg(arglst, void*);
	data->flags = ft_strdup("flags");
	printf("p_handler reached\n");
	return (1);
}
