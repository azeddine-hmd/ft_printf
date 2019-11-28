/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:40 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:53:42 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_handler(va_list arglst, t_lilst *data)
{
	char	arg;

	arg = va_arg(arglst, unsigned int);
	data->flags = ft_strdup("flags");
	printf("ft_x_handler reached\n");
	return (1);
}
