#include "ft_printf.h"

int		ft_percentage_handler(t_lilst *data)
{
	if (!(data->string = ft_strdup("%")))
			return (-1);
	return (1);
}
