/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 05:23:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/22 00:40:39 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dpre2int_maker(int iter, int *pre2int, char *s, va_list arglst)
{
	char	*precision;

	precision = NULL;
	if ((ft_get_precision(s, iter, &precision)) == -1)
		return (-1);
	if (precision == NULL)
		return (0);
	if (*precision == '*')
		*pre2int = va_arg(arglst, int);
	else
		*pre2int = ft_atoi(precision);
	return (1);
}

static char	*apply_precision(char *argument, int precision2int, char *flag)
{
	int		i;
	int		j;
	char	*argstr;

	if (*flag == '0')
		*flag = '\0';
	argstr = NULL;
	if (!(argstr = ft_bblank(precision2int, '0')))
		return (NULL);
	i = precision2int - ft_strlen(argument) - 1;
	j = 0;
	while (argstr[++i])
		argstr[i] = argument[j++];
	free(argument);
	return (argstr);
}

char		*dargstr_maker(int iter, char *s, va_list arglst, char *flag)
{
	int		precision2int;
	int		is_precisionExist;
	char	*argstr;
	char	*argument;

	precision2int = 0;
	if ((is_precisionExist = dpre2int_maker(iter, &precision2int, s, arglst))
			== -1)
		return (NULL);
	if (is_precisionExist == 0)
		return (ft_itoa(va_arg(arglst, int)));
	argstr = NULL;
	argument = ft_itoa(va_arg(arglst, int));
	if (precision2int == 0 && !ft_strncmp(argument, "0", ft_strlen(argument)))
		return (ft_strdup(""));
	if (precision2int > ft_strlen(argument))
	{
		if (!(argstr = apply_precision(argument, precision2int, flag)))
			return (NULL);
	}
	else
		argstr = argument;
	return (argstr);
}
