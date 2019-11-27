#include "ft_printf.h"

int		ft_percentage_handler(t_lilst *data)
{
	data->flags = ft_strdup("flags");
	printf("percentage_handler reached\n");
	return (1);
}
