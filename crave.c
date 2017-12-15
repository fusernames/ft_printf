#include "libftprintf.h"

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
		if (e->specifier == 'x' || e->specifier == 'p')
			buf[i++] = 'x';
		else if (e->specifier == 'X')
			buf[i++] = 'X';
	}
	return (i);
}

static int	width(t_spe *e, char *buf)
{
	int		buf_len;
	int		i;
	int		len;

	i = 0;
	buf_len = ft_strlen(buf);
	if ((len = e->width - buf_len) < 1)
		return (0);
	if (e->less)
	{
		while (i < len)
			buf[buf_len + i++] = ' ';
	}
	else
	{
		ft_memmove(&buf[len], buf, buf_len);
		while (i < len)
			buf[i++] = ' ';
	}
	return (i);
}

static int	precision(t_spe *e, char *buf)
{
	int	i;
	int	j;
	int	pre;

	i = 0;
	j = 0;
	pre = e->precision - ft_strlen(e->s);
	if (e->precision > 0 && pre > 0)
	{
		if (e->s[0] == '-')
		{
			pre++;
			buf[i++] = e->s[j++];
		}
		while(pre-- > 0)
			buf[i++] = '0';
	}
	while (e->s[j])
		buf[i++] = e->s[j++];
	return (i);
}

int	crave(t_spe *start)
{
	char	buf[4096];
	int	i;

	while(start)
	{
		i = 0;
		ft_bzero(buf, 4096);
		i += flags(start, buf);
		i += precision(start, &buf[i]);
		if (start->width > 0)
			i += width(start, buf);
		free(start->s);
		start->s = ft_strdup(buf);
		start = start->next;
	}
	return (1);
}
