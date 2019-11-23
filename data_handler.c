/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 08:21:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/23 08:22:05 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Description:
** - This function insert nodes and data in the "head".
** Return Values:
**  1: if everything went normal.
** -1: if an error occured (during allocation).
*/

int			data_handler(t_list *head, char *s, int start)
{
	char	specifier;
	char	*flags;
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == '%')
		{
			ft_lstadd_back(&head,
					new_data(NULL,
						get_specifier(s, i + 1), get_flags(s, i + 1)));
			i = get_specifier_index(s, start);
		}
	return (1);
}
