/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 04:41:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/06 09:43:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flag(char *s, int start, char *flag)
{
	char	*flags;
	int		i;
	int		j;

	if (!s)
		return(start);
	if (!(flags = ft_strdup("-+ #0")))
		return (-1);
	i = start - 1;
	while (s[++i])
	{
		j = -1;
		while (flags[++j])
		{
			if (s[i] == flags[j])
				if (!(*flag == '-' && flags[j] == '0'))
				{
					*flag = flags[j];
					break ;
				}
		}
		if (j == 5)
			break ;
	}
	free(flags);
	return (i);
}

int		ft_get_width(char *s, int start, char **width)
{
	int		i;
	int		len;

	if (!s)
		return(start);
	if (s[start] == '*')
	{
		len = 1;
		if (!(*width = ft_substr(s, start, len)))
			return (-1);
		return (start + len);
	}
	i = start - 1;
	len = 0;
	while (ft_isdigit(s[++i]))
		len++;
	if (len == 0)
		return (start + len);
	if (!(*width = ft_substr(s, start, len)))
		return (-1);
	return (start + len);
}

int		ft_get_precision(char *s, int start, char **precision)
{
	int		i;
	int		len;

	if (!s)
		return(start);
	if (s[start] == '.' && s[start + 1] == '*')
	{
		if (!(*precision = ft_substr(s, start + 1, 2)))
			return (-1);
		return (start + 2);
	}
	else if (s[start] == '.' && s[start + 1] != '*')
	{
		i = start;
		len = 0;
		while (ft_isdigit(s[++i]))
			len++;
		printf("len = '%d'\n", len);
		if (!(*precision = ft_substr(s, start + 1, len)))
			return (-1);
		return (len + start);
	}
	return (start);
}
