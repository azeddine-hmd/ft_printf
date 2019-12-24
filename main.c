#include "ft_printf.h"

int		main(void)
{
	int		re;

	re = ft_printf("'%-12.5d'", -666);
	printf("\nre = %d\n\n", re);
	re = printf("'%-12.5d'", -666);
	printf("\nre = %d\n", re);
	return (0);
}
