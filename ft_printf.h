/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 02:43:39 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/01/01 21:46:30 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_lilst
{
	char			*string;
	char			specifier;
	char			*flags;
	int				isnull;
	struct s_lilst	*next;
}				t_lilst;

int				ft_printf(const char *s, ...);
int				ft_insert_data(t_lilst **database, char *s);
t_lilst			*ft_new_data(char *string, char specifier, char *flags);
int				ft_get_specifier_index(char *s, int start);
char			ft_get_specifier(char *s, int start);
int				ft_get_flags(char *s, int start, char **adr_flags);
void			ft_lstadd_back(t_lilst **database, t_lilst *data);
int				ft_manipulate_data(t_lilst *database, va_list arglst);
int				ft_get_flag(char *s, int start, char *flag);
int				ft_get_width(char *s, int start, char **width);
int				ft_get_precision(char *s, int start, char **precision);
int				ft_c_handler(va_list arglst, t_lilst *data);
int				ft_s_handler(va_list arglst, t_lilst *data);
int				ft_p_handler(va_list arglst, t_lilst *data);
int				ft_d_handler(va_list arglst, t_lilst *data);
int				ft_i_handler(va_list arglst, t_lilst *data);
int				ft_u_handler(va_list arglst, t_lilst *data);
int				ft_x_handler(va_list arglst, t_lilst *data);
int				ft_capital_x_handler(va_list arglst, t_lilst *data);
int				ft_percentage_handler(va_list arglst, t_lilst *data);
int				ft_lstprint(t_lilst *database);
void			ft_lstclear(t_lilst *database);
int				width2int_maker(int *iterator, char *flag, char *s, va_list al);
char			*ft_bblank(int size, char c);
char			*argstr_maker(int iterator, char *s, va_list arglst);
char			*dargstr_maker(int iter, char *s, va_list arglst, char *flag);
char			*urgstr_maker(int iterator, char *s, va_list arglst);
char			*uargstr_maker(int iter, char *s, va_list arglst, char *flag);
char			*xrgstr_maker(int iterator, char *s, va_list arglst);
char			*xargstr_maker(int iter, char *s, va_list arglst, char *flag);
char			*cxrgstr_maker(int iterator, char *s, va_list arglst);
char			*cxargstr_maker(int iter, char *s, va_list arglst, char *flag);
char			*prgstr_maker(int iterator, char *s, va_list arglst);
char			*pargstr_maker(int iter, char *s, va_list arglst, char *flag);

#endif
