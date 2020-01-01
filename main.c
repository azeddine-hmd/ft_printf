#include "ft_printf.h"

int		main(void)
{
	int		re;

	re = ft_printf("result |'%-4c'", '\0');
	printf("\nreturn = %d\n\n", re);
	re = printf("result |'%-4c'", '\0');
	printf("\nreturn = %d\n", re);
	return (0);
}
