#include "ft_printf.h"

static int	flags(t_spe *e, char *buf)
{
	int	i;

	i = 0;
	if (e->space)
		buf[i++] = ' ';
	if (e->plus)
		buf[i++] = '+';
	if (e->hash)
	{
		buf[i++] = '0';
		if (e->specifier == 'x' || e->specifier == 'X')
			buf[i++] = e->specifier;
	}
	if (e->precision > 0)
		while(i < e->precision)
			buf[i++] = '0';
	return (i);
}

static int	width(t_spe *e, char *buf)
{
	char	c;
	int		buf_len;
	int		i;
	int		len;

	i = 0;
	c = ' ';
	buf_len = ft_strlen(buf);
	if ((len = e->width - buf_len) < 1)
		return (0);
	if (e->zero)
		c = '0';
	if (e->less)
	{
		while (i < len)
		{
			buf[len + i] = c;
			i++;
		}
	}
	else
	{
		ft_memmove(&buf[len], buf, buf_len);
		while (i < len)
			buf[i++] = c;
	}
	return (i);
}

int	crave(t_spe *start)
{
	char	buf[4096];
	int	i;

	i = 0;
	while(start)
	{
		ft_bzero(buf, 4096);
		i += flags(start, &buf[i]);
		ft_strcpy(&buf[i], (char *)start->s);
		i = ft_strlen(buf);
		i += width(start, buf);
		buf[i] = '\0';
		free(start->s);
		start->s = (unsigned char *)ft_strdup(buf);
		start = start->next;
	}
	return (1);
}
