/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:53:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/26 01:09:22 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_specifier_exist(char specifier, t_lilst *data)
{
	char	*all_specifiers;
	int		i;

	if (specifier == '\0')
		return (1);
	if (!(all_specifiers = ft_strdup("cspdiuxX%")))
		return (-1);
	i = -1;
	while (all_specifiers[++i])
		if (specifier == all_speifiers[i])
		{
			free(all_specifiers);
			if (call_specifier_handler(specifier, data) == -1)
				return (-1);
		}
	return (1);
}

int			data_modifier(t_lilst **head, va_list arglst)
{
	t_lilst		*data;

	data = *head;
	while (data)
	{
		if (is_specifier_exist(data->specifier, data) == -1)
			return (-1);
		data = data->next;
	}
	return (1);
}
