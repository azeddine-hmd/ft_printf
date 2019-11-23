/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:07:48 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/23 11:07:13 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Description:
** This function create a new node and initialize it.
** ------------------------------------------------------
** Return Values:
**	t_lilst*: address of the new node that have been created.
**  NULL: if an error occurred (during allocation).
*/

t_lilst		*new_data(char *string, char specifier, char *flags)
{
	t_lilst		*data;

	if (!((t_lilst*)malloc(sizeof(t_lilst))))
		return (NULL);
	data->str = str;
	data->specifier = specifier;
	data->flags = flags;
	data->next = NULL;
	return (data);
}

/*
** Description:
** - This function start from index "start" in string s ,
** and search for specifier to return his index.
** ------------------------------------------------------
** Return Values:
**	> 0: index of specifier in string s.
**  -1: if an error occurred (during allocation).
**	  0: if no specifier found in string s.
*/

int			get_specifier_index(char *s, int start)
{
	char	*all_specifiers;
	int		i;

	if (!(all_specifiers = ft_strdup("cspdiuxX%")))
		return (-1);
	i = start - 1;
	while (s[++i])
	{
		j = -1;
		while (all_specifiers[++j])
		{
			if (s[i] == all_specifiers[j])
			{
				free(all_specifiers);
				return (i);
			}
		}
	}
	return (0);
}

/*
** Return Values:
**  char: specifier character.
**    -1: if an error occurred (during allocation).
*/

char		get_specifier(char s, int start)
{
	char	specifier;

	specifier = s[get_specifier_index(s, start)];
	if (specifier == -1)
		return (-1);
	return (specifier);
}

/*
** Description:
** - This function get flags  and allocated in "adr_flags",
** and handles errors cases.
** Return Values:
**  1: if everything went normal.
** -1: if an error occurred (during allocation).
*/

int			get_flags(char *s, int start, char **adr_flags)
{
	int		end;
	int		len;

	end = get_specifier_index(s, start) - 1;
	len = end - start + 1;
	if (end < 0)
		return (-1);
	if (len == 0)
	{
		*adr_flags = NULL;
		return (1);
	}
	if (!(*adr_flags = ft_substr(s, start, len)))
		return (-1);
	return (1);
}
