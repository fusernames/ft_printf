#include "libftprintf.h"

char	*ft_getchar(char c)
{
	char	*s;
	s = malloc(2);
	s[0] = c;
	s[1] = '\0';

	return (s);
}
