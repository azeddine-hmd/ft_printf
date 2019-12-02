/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:34 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:53:36 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_u_handler(va_list arglst, t_lilst *data)
{
	unsigned int	arg;

	arg = va_arg(arglst, unsigned int);
	data->string = ft_strdup("string");
	printf("ft_u_handler reached\n");
	arg++;
	return (1);
}
