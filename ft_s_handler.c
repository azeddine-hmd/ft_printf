/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 05:31:11 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/06 10:28:52 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*string_maker(char flag, int width2int, char *argstr)
{
	char	*string;
	int		i;
	int		j;

	printf("argstr = '%s'\n", argstr);
	printf("width2int = '%d'\n", width2int);
	if (width2int <= ft_strlen(argstr))
		return (ft_strdup(argstr));
	if (!(string = ft_bblank(width2int)))
		return (NULL);
	if (flag == '-')
	{
		i = -1;
		while (argstr[++i])
			string[i] = argstr[i];
	}
	else if (flag == '\0')
	{
		i = 0;
		j = width2int - ft_strlen(argstr) - 1;
		while (argstr[++i])
			string[j++] = argstr[i];
	}
	return (string);
}

int				ft_s_handler(va_list arglst, t_lilst *data)
{
	int		iterator;
	char	flag;
	int		width2int;
	char	*argstr;

	iterator = 0;
	flag = '\0';
	if ((iterator = ft_get_flag(data->flags, iterator, &flag)) == -1)
		return (-1);
	if ((width2int = width2int_maker(&iterator, &flag, data->flags, arglst))
			== -1)
		return (-1);
	argstr = NULL;
	if (!(argstr = argstr_maker(iterator, data->flags, arglst)))
		return (-1);
	if (!(data->string = string_maker(flag, width2int, argstr)))
		return (-1);
	if (argstr)
		free(argstr);
	return (1);
}
