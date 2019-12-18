/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 01:35:12 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/07 14:15:17 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			width2int_maker(int *iterator, char *flag, char *s, va_list al)
{
	int		width2int;
	char	*width;

	width = NULL;
	if ((*iterator = ft_get_width(s, *iterator, &width)) == -1)
		return (-1);
	if (!width)
		return (0);
	width2int = 0;
	if (*width == '*')
		width2int = va_arg(al, int);
	else
		width2int = ft_atoi(width);
	if (width2int < 0)
	{
		width2int *= -1;
		*flag = '-';
	}
	if (width)
		free(width);
	return (width2int);
}

char		*ft_bblank(int size, char c)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(size)))
		return(NULL);
	i = -1;
	while (++i < size)
		str[i] = c;
	return (str);
}

static int	get_argument_string(va_list arglst, char *precision, char **argstr)
{
	int		precision2int;
	char	*str;

	if (!precision)
		return (1);
	if (*precision == '*')
		precision2int = va_arg(arglst, int);
	else
		precision2int = ft_atoi(precision);
	if (!(str = ft_strdup(va_arg(arglst, char*))))
			if (!(str = ft_strdup("(null)")))
				return (-1);
	if (precision2int >= ft_strlen(str) || precision2int < 0)
		*argstr = str;
	else
	{
		free(str);
		if (!(*argstr = ft_substr(str, 0, precision2int)))
			return (-1);
	}
	return (1);
}

char		*argstr_maker(int iterator, char *s, va_list arglst)
{
	char	*precision;
	char	*argstr;

	precision = NULL;
	if ((ft_get_precision(s, iterator, &precision) == -1))
				return (NULL);
	if (!precision)
		return (ft_strdup(va_arg(arglst, char*)));
	if (*precision == '\0')
	{
		free(precision); 
		if (!(precision = ft_strdup("0")))
			return (NULL);
	}
	argstr = NULL;
	if ((get_argument_string(arglst, precision, &argstr) == -1))
		return (NULL);
	if (precision)
		free(precision);
	return (argstr);
}
