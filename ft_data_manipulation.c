/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_manipulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:53:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/26 01:09:22 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier_handler(va_list arglst, t_lilst *data, char specifier)
{
	if (!data)
		return (-1);
	if (specifier == 'c')
		return (c_handler(arglst, data));
	//TODO: s_handler() ...
	return (-1);
}

int			data_manipulation(t_lilst **head, va_list arglst)
{
	t_lilst		*data;

	data = *head;
	while (data)
	{
		if (specifier_handler(arglst, data, data->specifier) == -1)
			return (-1);
		data = data->next;
	}
	return (1);
}
