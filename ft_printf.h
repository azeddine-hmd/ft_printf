#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>

typedef struct	s_lilst
{
	char			*string;
	char			specifier;
	char			*flags;
	struct s_lilst	*next;
}				t_lilst;

	int			ft_printf(const char *s, ...);
	int			data_handler(t_lilst **head, char *s);
	t_lilst		*new_data(char *string, char specifier, char *flags);
	int			get_specifier_index(char *s, int start);
	char		get_specifier(char *s, int start);
	int			get_flags(char *s, int start, char **adr_flags);
	void		lstadd_back(t_lilst **head, t_lilst *data);
	int			data_manipulation(t_lilst **head, va_list arglst);
	int			c_handler(va_list arglst, t_lilst *data);

#endif
