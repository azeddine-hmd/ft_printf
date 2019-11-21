#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_list
{
	char			*str;
	char			*operator;
	char			*flags;
	int				arg_index;
	struct s_list	next;
}				t_list;

	int		ft_printf(const char *s, ...);

#endif
