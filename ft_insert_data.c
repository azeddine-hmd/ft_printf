/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 08:21:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:50:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** [Description]:
** - This function add string data to the list
**
** [Return Values]:
**  1: if everything went normal.
** -1: if an error occurred (during allocation).
*/

static int		addlst_stringdata(t_lilst **database, char *s, int i, int start)
{
	t_lilst	*data;
	char	*string;
	int		s_length;

	s_length = ft_strlen(s);
	if (!s || i < 0 || i >= s_length)
		return (-1);
	if (!(string = ft_substr(s, start, (i - start + 1))))
		return (-1);
	if (!(data = ft_new_data(string, 0, NULL)))
		return (-1);
	ft_lstadd_back(database, data);
	return (1);
}

/*
** [Description]:
** - This function add formated data to the list
**
** [Return Values]:
**  1: if everything went normal.
** -1: if an error occurred (during allocation).
*/

static int		addlst_formatdata(t_lilst **database, char *s, int i)
{
	t_lilst	*data;
	char	specifier;
	char	*flags;
	int		flags_return;
	int		s_length;

	s_length = ft_strlen(s);
	if (!s || i < 0 || i >= s_length)
		return (-1);
	if ((specifier = ft_get_specifier(s, i)) == -1)
		return (-1);
	if ((flags_return = ft_get_flags(s, i, &flags)) == -1)
		return (-1);
	if (!(data = ft_new_data(NULL, specifier, flags)))
		return (-1);
	ft_lstadd_back(database, data);
	return (1);
}

/*
** [Description]:
** - This function insert data needed for [part II] in the "database".
**
** [Return Values]:
**  1: if everything went normal.
** -1: if an error occurced (during allocation).
*/

int				ft_insert_data(t_lilst **database, char *s)
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
			if ((format_return = addlst_formatdata(database, s, i + 1))
					== -1)
				return (-1);
			if ((i = ft_get_specifier_index(s, i + 1)) == -1)
				return (-1);
			start = i + 1;
			if (s[i + 1] == '\0')
				break ;
		}
		else if (s[i] != '%' && (s[i + 1] == '%' || s[i + 1] == '\0'))
			if ((string_return = addlst_stringdata(database, s, i, start))
					== -1)
				return (-1);
	}
	return (1);
}
