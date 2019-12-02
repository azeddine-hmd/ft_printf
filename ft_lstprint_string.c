#include "ft_printf.h"

int		ft_lstprint_string(t_lilst *database)
{
	t_lilst		*data;
	int			output_len;

	data = database;
	output_len = 0;
	while (data)
	{
		ft_putstr_fd(data->string, 1);
		output_len += ft_strlen(data->string);
		data = data->next;
	}
	return (output_len);
}
