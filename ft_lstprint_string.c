/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:40:13 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/29 16:42:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
