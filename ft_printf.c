/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:28:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/25 20:14:32 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_lilst		*database;
	va_list		arglst;

	// [PART I]: inserting data in the list.
	database = NULL;
	if (data_handler(&database, (char*)s) == -1)
		return (-1);

	// [PART II] modifying all data in the list.
	va_start(arglst, s);
	if (data_manipulation(database, arglst) == -1)
		return (-1);
	va_end(arglst);

	// [PART III] join and free
	//TODO: join all string data.
	//TODO: free list.

	return (1);
}
