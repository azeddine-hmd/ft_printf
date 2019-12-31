/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_manipulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:53:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/31 17:04:33 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier_handler(va_list arglst, t_lilst *data, char specifier)
{
	if (!data)
		return (-1);
	if (specifier == 'c')
		return (ft_c_handler(arglst, data));
	else if (specifier == 's')
		return (ft_s_handler(arglst, data));
	else if (specifier == 'p')
		return (ft_p_handler(arglst, data));
	else if (specifier == 'd')
		return (ft_d_handler(arglst, data));
	else if (specifier == 'i')
		return (ft_i_handler(arglst, data));
	else if (specifier == 'u')
		return (ft_u_handler(arglst, data));
	else if (specifier == 'x')
		return (ft_x_handler(arglst, data));
	else if (specifier == 'X')
		return (ft_capital_x_handler(arglst, data));
	else if (specifier == '%')
		return (ft_percentage_handler(arglst, data));
	return (-1);
}

int			ft_manipulate_data(t_lilst *database, va_list arglst)
{
	t_lilst		*data;

	data = database;
	while (data)
	{
		if (data->specifier != '\0')
			if (specifier_handler(arglst, data, data->specifier)
					== -1)
				return (-1);
		data = data->next;
	}
	return (1);
}
