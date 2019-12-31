/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:36:37 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/29 14:41:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** [Description]:
** This function search the last data in the list,
** and return it.
**
** [Return Values]:
**  t_lilst*: the last "data" in the list.
**      NULL: if no "data" found in the list.
*/

static t_lilst	*lstlast(t_lilst *data)
{
	if (!data)
		return (NULL);
	while (data->next)
		data = data->next;
	return (data);
}

/*
** [Description]:
** This function add "data" data to the front of the list.
*/

static void		lstadd_front(t_lilst **database, t_lilst *data)
{
	if (*database)
		data->next = *database;
	else
		*database = data;
}

/*
** [Description]:
** This function add data (node) to the list.
** if list is empty it add it in the front.
*/

void			ft_lstadd_back(t_lilst **database, t_lilst *data)
{
	if (!*database)
		lstadd_front(database, data);
	else
		(lstlast(*database))->next = data;
}

static void		lstremove(t_lilst *data)
{
	if (!data)
		return ;
	if (data->string)
		free(data->string);
	data->string = NULL;
	if (data->flags)
		free(data->flags);
	data->flags = NULL;
	data->next = NULL;
	data->specifier = '\0';
	free(data);
}

void			ft_lstclear(t_lilst *database)
{
	t_lilst		*tmp;

	while (database)
	{
		tmp = database->next;
		lstremove(database);
		database = tmp;
	}
}
