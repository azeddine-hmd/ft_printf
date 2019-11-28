/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:04 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:58:34 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_handler(va_list arglst, t_lilst *data)
{
	char	arg;
	char	*flag;
	char	*width

	arg = va_arg(arglst, int);
	printf("ft_c_handler reached\n");
	ft_split
	return (1);
}
