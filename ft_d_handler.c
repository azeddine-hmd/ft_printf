/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/22 10:27:21 by ahamdaou         ###   ########.fr       */
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
    if (flag == '\0')
	if (!(string = ft_bblank(width2int, ' ')))
	    return (NULL);
    if (flag == '0')
	if (!(string = ft_bblank(width2int, '0')))
	    return (NULL);
    if (flag == '-')
    {
	i = -1;
	while (argstr[++i])
	    string[i] = argstr[i];
    }
    else
    {
	i = -1;
	j = width2int - ft_strlen(argstr);
	while (argstr[++i])
	    string[j++] = argstr[i];
    }
    return (string);
}

int		ft_d_handler(va_list arglst, t_lilst *data)
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
    if (!(data->string = string_maker(flag, width2int, argstr)))
	return (-1);
    free(argstr);
    return (1);
}
