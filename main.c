#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	ft_printf("%d\n", ft_printf("42 - 84 is %x\n", NULL));
	printf("%d\n", printf("42 - 84 is %p\n", NULL));
	return (0);
}
