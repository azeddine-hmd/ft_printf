/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/27 23:53:19 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*argstr_maker(int iterator, char *s, va_list arglst, char *flag)
{
	int		precision2int;
	char	*argstr;

	if ((precision2int_maker(iterator, &precision2int, s, argstr)) == -1)	
			return (-1);
	printf("precision2int = %d\n", precision2int);
}

int				ft_d_handler(va_list arglst, t_lilst *data)
{
	int		iterator;
	char	flag;
	int		width2int;
	char	*argstr;

	iterator = 0;
	flag = '\0';
	if ((iterator = ft_get_flag(data->flags, iterator, &flag)) == -1)
		return (-1);
	width2int = 0;
	if ((width2int = width2int_maker(&iterator, &flag, data->flags, arglst))
			== -1)
		return (-1);
	if (!(argstr = argstr_maker(iterator, data->flags, arglst, &flag)))
			return (-1);
	return (1);
}
