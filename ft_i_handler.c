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
	int		i;

	i = va_arg(arglst, int);
	data->flags = ft_strdup("flags");
	printf("ft_i_handler reached\n");
	return (1);
}
