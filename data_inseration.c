/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_inseration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:07:48 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/21 22:16:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		newData(char *str, char *operator, char *flags, int arg_index)
{
	t_list		*data;

	if (!((t_list*)malloc(sizeof(t_list))))
		return (NULL);
	data->str = str;
	data->operator = operator;
	data->flags = flags;
	data->arg_index = arg_index;
	data->next = NULL;
	return (data);
}

int			data_handler(char *s, int start)
{
	
}
