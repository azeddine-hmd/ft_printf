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
<<<<<<< HEAD
=======
	char	*flag;
	char	*width;
	char	*precision;
>>>>>>> ec664de6d8d454ef7b79b3f467906ec1fb0cf871

	flag = NULL;
	width = NULL;
	precision = NULL;
	ft
	arg = va_arg(arglst, int);
	data->string = ft_strdup("lol");
	printf("ft_c_handler reached\n");
<<<<<<< HEAD
=======
	
>>>>>>> ec664de6d8d454ef7b79b3f467906ec1fb0cf871
	return (1);
}
