#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("return: %d\n", ft_printf("%%%c%c%c%%"));
	return (0);
}
