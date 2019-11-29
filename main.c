#include "ft_printf.h"

int		main(void)
{
	printf("ft_printf return: %d\n", ft_printf("\n\n'%23c'\n", 'a'));
	printf("\n\n'%0c'\n", 'a');
	return (0);
}
