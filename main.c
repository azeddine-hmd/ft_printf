#include "ft_printf.h"

int		main(void)
{
	int		re;

	printf("||ft_printf||\n");
	re = ft_printf("result |TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
	printf("\nreturn = %d\n\n", re);
	printf("||printf||\n");
	re = printf("result |TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
	printf("\nreturn = %d\n", re);
	return (0);
}
