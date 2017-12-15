#include "libftprintf.h"

static int	add_flags(t_spe *e, char *buf)
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

static int	add_str(t_spe *e, char *buf)
{
	int	i;
	int	j;
	int	pre;

	i = 0;
	j = 0;
	pre = e->precision;
	if (e->specifier != 's' && e->specifier != 'S')
	{
		pre += ft_strlen(e->s);
		if (e->precision > 0 && (pre > 0 || e->width == -1))
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
	}
	else
	{
		while(e->s[j] && pre--)
			buf[i++] = e->s[j++];
	}
	return (i);
}

static int	add_width(t_spe *e, char *buf, int flags)
{
	int		buf_len;
	int		i;
	int		len;
	char		c;

	i = 0;
	c = ' ';
	buf_len = ft_strlen(buf);
	len = e->width - buf_len;
	if (e->zero)
	{
		c = '0';
		buf += flags;
	}
	if (e->less)
		while (i < len)
			buf[buf_len + i++] = c;
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
	int	flags;

	while(start)
	{
		flags = 0;
		ft_bzero(buf, 4096);
		flags = add_flags(start, buf);
		add_str(start, &buf[flags]);
		if (start->width > 0)
			add_width(start, buf, flags);
		free(start->s);
		start->s = ft_strdup(buf);
		start = start->next;
	}
	return (1);
}
