/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/01/01 00:09:55 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_zero(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

static int	negative_andwidth(int width2int, char **argstr, char **string)
{
	char *tmp;

	if (**argstr == '-' && !is_zero(*(*argstr + 1)))
	{
		tmp = *argstr;
		*argstr = ft_substr(*argstr, 1, ft_strlen(*argstr) - 1);
		if (!(*argstr))
			return (-1);
		free(tmp);
		if (!(*string = ft_bblank(width2int, '0')))
			return (-1);
		**string = '-';
	}
	else
	{
		if (!(*string = ft_bblank(width2int, '0')))
			return (-1);
	}
	return (1);
}

static char	*string_maker(char flag, int width2int, char **argstr)
{
	char	*string;
	int		i;
	int		j;

	if (width2int <= ft_strlen(*argstr))
		return (ft_strdup(*argstr));
	if (flag == '\0' || flag == '-')
		if (!(string = ft_bblank(width2int, ' ')))
			return (NULL);
	if (flag == '0')
		if (negative_andwidth(width2int, argstr, &string) == -1)
			return (NULL);
	i = -1;
	if (flag == '-')
		while ((*argstr)[++i])
			string[i] = (*argstr)[i];
	else
	{
		i = -1;
		j = width2int - ft_strlen(*argstr);
		while ((*argstr)[++i])
			string[j++] = (*argstr)[i];
	}
	return (string);
}

int			ft_d_handler(va_list arglst, t_lilst *data)
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
	if (!(argstr = dargstr_maker(iterator, data->flags, arglst, &flag)))
		return (-1);
	if (!(data->string = string_maker(flag, width2int, &argstr)))
		return (-1);
	free(argstr);
	return (1);
}
