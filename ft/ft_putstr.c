#include "libftprintf.h"

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
