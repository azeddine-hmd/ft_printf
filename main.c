#include "ft_printf.h"

int		main(void)
{
	char	*s;
	int		re;

	s  = "noice";
	re = ft_printf("'%s'", s);
	printf("\nre = %d\n", re);
	return (0);
}
