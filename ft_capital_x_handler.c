/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capital_x_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:53:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_capital_x_handler(va_list arglst, t_lilst *data)
{
	char	arg;

	data->string = ft_strdup("string");
	printf("ft_capital_x_handler reached\n");
	arg = va_arg(arglst, unsigned int);
	return (1);
}
