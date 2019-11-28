/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:04 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/28 12:20:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_handler(va_list arglst, t_lilst *data)
{
	char	arg;
	char	*flag;
	char	*width;
	char	*precision;

	flag = NULL;
	width = NULL;
	precision = NULL;
	ft
	arg = va_arg(arglst, int);
	data->string = ft_strdup("lol");
	printf("ft_c_handler reached\n");
	
	return (1);
}
