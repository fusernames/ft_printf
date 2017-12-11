#include "ft_printf.h"

void	printbyte(unsigned char c)
{
	int i;
	i = 0;

	while (i < 8)
	{
		printf("%d", !!((c << i) & 128));
		i++;
	}
	printf(" ");
}

unsigned char	*ft_getwchar(wchar_t c)
{
	unsigned char	*ret;

	if ((ret = malloc(5)) == NULL)
		return (NULL);
	ft_bzero(ret, 5);
	if (c <= 2047)
	{
		ret[0] = (((c >> 6) & 31) + 192);
		ret[1] = ((c & 63) + 128);
	}
	else if (c <= 65535)
	{
		ret[0] = (((c >> 12) & 15) + 224);
		ret[1] = (((c >> 6) & 63) + 128);
		ret[2] = ((c & 63) + 128);
	}
	else
	{
		ret[0] = (((c >> 18) & 7) + 240);
		ret[1] = (((c >> 12) & 63) + 128);	
		ret[2] = (((c >> 6) & 63) + 128);	
		ret[3] = ((c & 63) + 128);	
	}
	return (ret);
}

unsigned char	*ft_getwstr(wchar_t *str)
{
	unsigned char 	*ret;
	unsigned char	*wc;
	int			i;
	int 			j;

	i = 0;
	if ((ret = malloc(ft_strlen((char *)str) * 4 + 1)) == NULL)
		return (NULL);
	while (*str)
	{
		if (*str <= 127)
			ret[i++] = *str;
		else
		{
			j = 0;
			if ((wc = ft_getwchar(*str)) == NULL)
				return (NULL);
			while (wc[j])
				ret[i++] = wc[j++];
			free(wc);
		}
		str++;
	}
	return (ret);
}
