/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:04 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/04 04:12:50 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_bblank(int size)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(size)))
		return(NULL);
	i = -1;
	while (++i < size)
		str[i] = ' ';
	return (str);
}

int		ft_width_maker(va_list arglst, char flag, char *width, char **string)
{
	int		width2int;

	if (!width)
		return (1);
	if (*width == '*')
		width2int = va_arg(arglst, int);
	else
		width2int = ft_atoi(width);
	if (width2int < 0)
	{
		width2int *= -1;
		flag = '-';
	}
	if (!(*string = ft_bblank(width2int)))
		return (-1);
	if (flag == '-')
		**string = va_arg(arglst, int);
	if (flag == '\0')
		*(*string + (width2int - 1)) = va_arg(arglst, int);
	return (1);
}

int		ft_c_handler(va_list arglst, t_lilst *data)
{
	char	*string;
	char	*width;
	int		start;
	char	flag;

	if (!data->flags)
	{
		if (!(data->string = ft_calloc(sizeof(char), 2)))
			return (-1);
		(data->string)[0] = va_arg(arglst, int);
		return (1);
	}
	start = 0;
	flag = '\0';
	if ((start = ft_get_flag(data->flags, start, &flag)) == -1)
		return (-1);
	width = NULL;
	if (ft_get_width(data->flags, start, &width) == -1)
		return (-1);
	string = NULL;
	if (ft_width_maker(arglst, flag, width, &string) == -1)
		return (-1);
	data->string = string;
	if (width)
		free(width);
	return (1);
}
