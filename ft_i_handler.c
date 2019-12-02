/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:26 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:53:28 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_i_handler(va_list arglst, t_lilst *data)
{
	int		arg;

	arg = va_arg(arglst, int);
	data->string = ft_strdup("string");
	printf("ft_i_handler reached\n");
	arg++;
	return (1);
}
