#include "ft_printf.h"

int		main(void)
{
	char	*s;
	int		re;

	s  = "noice";
	re = ft_printf("'%.*s'", 23, s);
	printf("\nre = %d\n\n", re);
	re = printf("'%.*s'", 23, s);
	printf("\nre = %d\n", re);
	return (0);
}
