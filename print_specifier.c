/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 15:08:42 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/24 16:50:50 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_flags(t_spe *e, char **s, char *buf, int print)
{
	char	c;
	int		i;

	c = e->spe;
	i = 0;
	if (e->space)
		buf[i++] = ' ';
	if (e->plus)
		buf[i++] = '+';
	if (e->hash)
	{
		buf[i++] = '0';
		if (c == 'x' || c == 'p')
			buf[i++] = 'x';
		else if (e->spe == 'X')
			buf[i++] = 'X';
	}
	if (*s && *s[0] == '-' && (c == 'd' || c == 'D' || c == 'i'))
	{
		buf[i++] = '-';
		if (print)
			(*s)++;
	}
	buf[i] = '\0';
	return (print ? ft_putstr(buf) : i);
}

static int	print_width(t_spe *e, int flags, char *s, char *buf)
{
	int		i;
	int		len;
	char	c;
	int		s_len;

	i = 0;
	c = ' ';
	len = 0;
	s_len = ft_strlen(s);
	if (s && s[0] == '-' && (e->spe == 'd' || e->spe == 'D' || e->spe == 'i')
			&& e->precision < s_len)
		len++;
	if (e->precision > 0 && e->precision - s_len > 0)
		len -= e->precision - s_len;
	if ((len += e->width - (s_len + flags)) > 0)
	{
		if (s && e->s[0] == '\0' && (e->spe == 'c' || e->spe == 'C'))
			len--;
		if (e->zero)
			c = '0';
		while (i < len)
			buf[i++] = c;
	}
	buf[i] = '\0';
	return (ft_putstr(buf));
}

static int	print_precision(t_spe *e, char *s, char *buf)
{
	int	i;
	int	len;

	i = 0;
	len = e->precision - ft_strlen(s);
	if ((e->spe == 'o' || e->spe == 'O') && e->hash == 1)
		len--;
	if (len > 0 && e->spe != 's' && e->spe != 'S')
	{
		while (i < len)
			buf[i++] = '0';
	}
	buf[i] = '\0';
	return (ft_putstr(buf));
}

static int	print_s(t_spe *e, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (e->precision > -1 && (e->spe == 's' || e->spe == 'S'))
		len = e->precision;
	if (s[i] == '\0' && (e->spe == 'c' || e->spe == 'C'))
		ft_putchar(s[i++]);
	while (i < len && s[i])
		ft_putchar(s[i++]);
	return (i);
}

int			print_specifier(t_spe *e)
{
	char	*s;
	char	buf[4096];
	int		i;
	int		flags;

	s = e->s;
	i = 0;
	flags = print_flags(e, &s, buf, 0);
	if (e->width > 0 && !e->minus && !e->zero)
		i += print_width(e, flags, s, buf);
	i += print_flags(e, &s, buf, 1);
	if (e->width > 0 && e->zero)
		i += print_width(e, flags, s, buf);
	if (e->precision > 0 && e->spe != 's' && e->spe != 'S')
		i += print_precision(e, s, buf);
	if (e->precision || ft_strcmp(s, "0") || e->spe == 'o' || e->spe == 'O')
		i += print_s(e, s);
	if (e->width > 0 && e->minus)
		i += print_width(e, flags, s, buf);
	return (i);
}
