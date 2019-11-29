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
	char	flag;
	char	*width;
	char	*precision;
	int		index;

	flag = '\0';
	width = NULL;
	precision = NULL;
	arg = va_arg(arglst, int);
	printf("argument = %c\n", arg);
	if ((index = ft_get_flag(data->flags, 0, &flag)) == -1)
			return (-1);
	if ((index = ft_get_width(data->flags, index, &width)) == -1)
			return (-1);
	if ((index = ft_get_precision(data->flags, index, &precision)) == -1)
			return (-1);
	printf("flag = %c\n", flag);
	printf("width = %s\n", width);
	printf("precision = %s\n\n", precision);
	return (1);
}
