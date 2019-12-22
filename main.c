#include "ft_printf.h"

int		main(void)
{
	int		re;

	re = ft_printf("'%015d'", 666);
	printf("\nre = %d\n\n", re);
	re = printf("'%015i'", 666);
	printf("\nre = %d\n", re);
	return (0);
}
