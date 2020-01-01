/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:40:13 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/01/01 22:41:54 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lstprint(t_lilst *database)
{
	t_lilst		*data;
	int			output_len;
	char		*str;

	data = database;
	output_len = 0;
	while (data)
	{
		str = data->string;
		if (data->isnull == 2)
		{
			ft_putstr_fd(str + 1, 1);
			ft_putchar_fd(0, 1);
		}
		else if (data->isnull == 3)
		{
			ft_putchar_fd(0, 1);
			ft_putstr_fd(str + 1, 1);
		}
		else
			ft_putstr_fd(str, 1);
		data = data->next;
		output_len += ft_strlen(str);
	}
	return (output_len);
}
