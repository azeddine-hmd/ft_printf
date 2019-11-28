/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:53:19 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d_handler(va_list arglst, t_lilst *data)
{
	int		arg;

	arg = va_arg(arglst, int);
	data->flags = ft_strdup("flags");
	printf("ft_d_handler reached\n");
	return (1);
}
