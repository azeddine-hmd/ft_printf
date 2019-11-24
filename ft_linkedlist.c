/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:36:37 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/24 20:55:30 by ahamdaou         ###   ########.fr       */
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

static t_lilst	*lstlast(t_lilst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
** [Description]:
** This function add "data" data to the front of the list.
*/

static void		lstadd_front(t_lilst **head, t_lilst *data)
{
	if (*head)
		data->next = *head;
	else
		*head = data;
}

/*
** [Description]:
** This function add data (node) to the list.
** if list is empty it add it in the front.
*/

void			lstadd_back(t_lilst **head, t_lilst *data)
{
	if (!*head)
		lstadd_front(head, data);
	else
		(lstlast(*head))->next = data;
}
