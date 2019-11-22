/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_inseration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:07:48 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/22 23:08:41 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		newData(char *string, char *specifier, char *flags, int arg_index)
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

char	*get_operator(char *s, int start)
{
	
}

int			data_handler(t_list *head, char *s, int start)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
			ft_lstadd_back(&head,
					newData(NULL,
					get_operator(s, i + 1),
					get_flags));	

	}
}
