/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 05:23:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/22 10:49:30 by ahamdaou         ###   ########.fr       */
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
	free(precision);
	return (1);
}

static char	*negative_condition(char *argument, int precision2int, char *flag)
{
	int		i;
	int		j;
	char	*argstr;
	char	*argumentnew;

	argumentnew = ft_substr(argument, 1, ft_strlen(argument) - 1);
	if (*flag == '0')
		*flag = '\0';
	argstr = NULL;
	if (!(argstr = ft_bblank(precision2int + 1, '0')))
		return (NULL);
	*argstr = '-';
	i = precision2int - ft_strlen(argumentnew);
	j = 0;
	while (argstr[++i])
		argstr[i] = argumentnew[j++];
	free(argumentnew);
	free(argument);
	return (argstr);
}

static char	*apply_precision(char *argument, int precision2int, char *flag)
{
	int		i;
	int		j;
	char	*argstr;

	if (*argument == '-')
		return (negative_condition(argument, precision2int, flag));
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
	int		is_precisionexist;
	char	*argstr;
	char	*argument;

	if ((is_precisionexist = dpre2int_maker(iter, &precision2int, s, arglst))
			== -1)
		return (NULL);
	if (is_precisionexist == 0)
		return (ft_itoa(va_arg(arglst, int)));
	argstr = NULL;
	argument = ft_itoa(va_arg(arglst, int));
	if (precision2int == 0 && !ft_strncmp(argument, "0", ft_strlen(argument)))
		return (ft_strdup(""));
	if (precision2int > ft_strlen(argument))
		if (!(argstr = apply_precision(argument, precision2int, flag)))
			return (NULL);
	if (precision2int <= ft_strlen(argument))
		argstr = argument;
	return (argstr);
}
