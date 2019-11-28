/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 04:41:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/28 12:11:30 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flag(char *s, int start, char *flag)
{
	char	*flags;
	int		i;
	int		specifier_index;

	if (!(flags = ft_strdup("-+ #0")))
		return (-1);
	i = -1;
	while (flags[++i])
		if (s[start] == flags[i])
		{
			free(flags);
			*flag = s[start];
			return (start + 1);
		}
	free(flags);
	return (0);
}

int		ft_get_width(char *s, int start, char **width)
{
	int		i;
	int		len;
	
	i = start - 1;
	len = 0;
	while (ft_isdigit(s[++i]))
		len++;
	if (!(*width = ft_substr(s, start, len)))
		return (-1);
	return (start + len);
}

int		ft_get_precision(char *s, int start, char **precision)
{
	int		i;
	int		len;

	if (s[start] == '.' && s[start + 1] == '*')
	{
		if (!(*precision = ft_substr(s, start, 2)))
			return (-1);
		return (start + 2);
	}
	else if (s[start] == '.' && s[start + 1] != '*')
	{
		i = start;
		len = 1;
		while (ft_isdigit(s[++i]))
			len++;
		if (!(*precision = ft_substr(s, start, len)))
			return (-1);
		printf("len = %d\n", len);
		return (len + start);
	}
	return (start);
}
