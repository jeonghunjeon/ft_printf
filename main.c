#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;

	ft_printf("%d\n", ft_printf("%u\n%x\n%p\n", 3, 140, &str));
	printf("%d\n", printf("%u\n%x\n%p\n", 3, 140, &str));
	return (0);
}
