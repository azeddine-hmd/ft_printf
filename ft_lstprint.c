/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:40:13 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/01/02 02:52:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printstring(t_lilst *data, char *str, int *output_len)
{
	if (data->isnull == 2)
	{
		ft_putstr_fd(str + 1, 1);
		ft_putchar_fd(0, 1);
		if (*str == '\0')
			*output_len += 1;
	}
	else if (data->isnull == 3)
	{
		ft_putchar_fd(0, 1);
		ft_putstr_fd(str + 1, 1);
		if (*str == '\0')
			*output_len += 1;
	}
	else
		ft_putstr_fd(str, 1);
}

int			ft_lstprint(t_lilst *database)
{
	t_lilst		*data;
	int			output_len;
	char		*str;

	data = database;
	output_len = 0;
	while (data)
	{
		str = data->string;
		printstring(data, str, &output_len);
		output_len += ft_strlen(str);
		data = data->next;
	}
	return (output_len);
}
