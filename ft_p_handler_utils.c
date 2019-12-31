/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:30:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/30 20:11:15 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ppre2int_maker(int iter, int *pre2int, char *s, va_list arglst)
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

static char	*prefixer(char *s)
{
	char	*final;

	if(!(final = ft_strjoin("0x", s)))
		return (NULL);
	free(s);
	return (final);
}

char		*pargstr_maker(int iter, char *s, va_list arglst, char *flag)
{
	int		precision2int;
	int		is_precisionexist;
	char	*argstr;
	char	*argument;

	if ((is_precisionexist = ppre2int_maker(iter, &precision2int, s, arglst))
			== -1)
		return (NULL);
	if (is_precisionexist == 0)
		return (prefixer(ft_dec2hex(va_arg(arglst, size_t))));
	argstr = NULL;
	argument = prefixer(ft_dec2hex(va_arg(arglst, size_t)));
	if (precision2int == 0 && !ft_strncmp(argument, "0", ft_strlen(argument)))
	{
		free(argument);
		return (ft_strdup(""));
	}
	if (precision2int > ft_strlen(argument))
		if (!(argstr = apply_precision(argument, precision2int, flag)))
			return (NULL);
	if (precision2int <= ft_strlen(argument))
		argstr = ft_strdup(argument);
	free(argument);
	return (argstr);
}
