/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:54:01 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:54:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_handler(va_list arglst, t_lilst *data)
{
	void	*arg;

	arg = va_arg(arglst, void*);
	data->flags = ft_strdup("flags");
	printf("ft_p_handler reached\n");
	return (1);
}
