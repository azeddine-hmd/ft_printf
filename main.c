#include "ft_printf.h"

int		main(void)
{
	int		re;

	re = ft_printf("'%u'", -2222);
	printf("\nre = %d\n\n", re);
	re = printf("'%u'", -2222);
	printf("\nre = %d\n", re);
	return (0);
}
