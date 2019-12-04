/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:28:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/04 04:10:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_lilst		*database;
	va_list		arglst;
	int			output_len;

	// [PART I]: inserting data in the list.
	database = NULL;
	if (ft_insert_data(&database, (char*)s) == -1)
		return (-1);

	// [PART II] modifying all data in the list.
	va_start(arglst, s);
	if (ft_manipulate_data(database, arglst) == -1)
		return (-1);
	va_end(arglst);

	// [PART III] join and free
	output_len = 0;
	if ((output_len = ft_lstprint_string(database)) == -1)
		return (-1);
	ft_lstclear(database);
	database = NULL;

	return (output_len);
}
