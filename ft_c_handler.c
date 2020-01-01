/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:04 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/01/01 22:25:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*string_maker(char flag, int width2int, char *argstr)
{
	char	*string;
	int		i;
	int		j;

	if (width2int <= ft_strlen(argstr))
		return (ft_strdup(argstr));
	if (flag == '\0' || flag == '-')
		if (!(string = ft_bblank(width2int, ' ')))
			return (NULL);
	if (flag == '0')
		if (!(string = ft_bblank(width2int, '0')))
			return (NULL);
	i = -1;
	if (flag == '-')
		while (argstr[++i])
			string[i] = argstr[i];
	else
	{
		i = -1;
		j = width2int - ft_strlen(argstr);
		while (argstr[++i])
			string[j++] = argstr[i];
	}
	return (string);
}

static char	*getstr(t_lilst *data, char flag, va_list arglst)
{
	char	c;
	char	*argstr;

	c = (char)va_arg(arglst, int);
	if (c == '\0')
	{
		if (flag == '\0')
			data->isnull = 2;
		if (flag == '-')
			data->isnull = 3;
		if (!(argstr = ft_strdup("")))
			return (NULL);
		return (argstr);
	}
	else
	{
		if (!(argstr = ft_strdup("f")))
			return (NULL);
		*argstr = c;
		return (argstr);
	}
}

int			ft_c_handler(va_list arglst, t_lilst *data)
{
	int		width2int;
	int		iterator;
	char	flag;
	char	*argstr;

	iterator = 0;
	flag = '\0';
	if ((iterator = ft_get_flag(data->flags, iterator, &flag)) == -1)
		return (-1);
	width2int = 0;
	if ((width2int = width2int_maker(&iterator, &flag, data->flags, arglst))
			== -1)
		return (-1);
	argstr = NULL;
	if (!(argstr = getstr(data, flag, arglst)))
		return (-1);
	if (!(data->string = string_maker(flag, width2int, argstr)))
		return (-1);
	free(argstr);
	return (1);
}
