#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("return: %d\n", ft_printf("TEST%%%c%c%c%%TEST"));
	return (0);
}
