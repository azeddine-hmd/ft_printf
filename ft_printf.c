/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:28:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/24 22:55:41 by ahamdaou         ###   ########.fr       */
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
	printf("data(2)->string = '%c'\n", (head->next)->specifier);
	printf("data(2)->specifier = '%c'\n", (head->next)->specifier);
	printf("data(2)->specifier = '%c'\n", (head->next)->specifier);

	//TODO: part2: modify nodes data	
	return (0);
}
