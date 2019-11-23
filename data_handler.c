/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 08:21:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/23 11:11:55 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Description:
** - This function add string data to the list
** Return Values:
**  1: if everything went normal.
** -1: if an error occurred (during allocation).
*/

static int		addlst_stringdata(t_lilst **head, char *s, int i, int *start)
{
	char	*string;

	if (!(string = ft_substr(s, *start, (i - *start + 1))))
		return (-1);
	ft_lstadd_back(head, new_data(string, 0, NULL));
}

/*
** Description:
** - This function add formated data to the list
** Return Values:
**  1: if everything went normal.
** -1: if an error occurred (during allocation).
*/

static int		addlst_formatdata(t_lilst **head, char *s, int i, int *start)
{
	char	specifier;
	char	*flags;
	int		flags_return;

	if ((specifier = get_specifier(s, i + 1)) == -1)
		return (-1);
	if ((flags_return = get_flags(s, i + 1, &flags)) == -1)
		return (-1);
	ft_lstadd_back(head, new_data(NULL, specifier, flags));
	*start = i + 1;
	return (1);
}

/*
** Description:
** - This function insert nodes and data in the "head".
** Return Values:
**  1: if everything went normal.
** -1: if an error occurced (during allocation).
*/

int				data_handler(t_lilst **head, char *s)
{
	int		start;
	int		format_return;
	int		string_return;
	int		i;

	i = -1;
	start = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if ((format_return = addlst_formatdata(head, s, i, &start)) == -1)
				return (-1);
			if ((i = get_specifier_index(s, i)) == -1)
				return (-1);
		}
		else if (s[i] != '%' && (s[i + 1] == '%' || s[i + 1] == '\0'))
			if ((string_return = addlst_stringdata(head, s, i, &start)) == -1)
				return (-1);
	}
	return (1);
}
