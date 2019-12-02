#include "ft_printf.h"

int		main(void)
{
	ft_printf("%-12c %c %*c  %%%%", 'a', 'b', -3, 'd');
	return (0);
}
