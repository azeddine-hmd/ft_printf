/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:28:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/25 02:43:37 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *s, ...)
{
	t_lilst		*head;

	head = NULL;
	data_handler(&head, (char*)s);
	printf("data(1)->string = '%s'\n", (head->string);
	printf("\n<=====================>\n");
	printf("data(2)->string = '%c'\n", (head->next)->string);
	printf("data(2)->specifier = '%c'\n", (head->next)->specifier);
	printf("data(2)->flags '%c'\n", (head->next)->flags);
	printf("\n<=====================>\n");
	if ((head->next)-next == NULL)
		printf("\n[NO MORE DATA LEFT]\n");
	//TODO: part2: modify nodes data
	return (0);
}
