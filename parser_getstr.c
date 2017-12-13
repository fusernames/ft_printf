/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:12:25 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/11 19:56:31 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(char c, void *n)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (itoa_base(*((long long*)n), 10));
	if (c == 'X')
		return (itoa_base_un(*((unsigned long long*)n), 16));
	if (c == 'x' || c == 'p')
		return (ft_strtolower(itoa_base_un(*((unsigned long long*)n), 16)));
	if (c == 'o' || c == 'O')
		return (itoa_base_un(*((unsigned long long*)n), 8));
	if (c == 'u' || c == 'U')
		return (itoa_base_un(*((unsigned long long*)n), 10));
	return (NULL);
}

static int	handle_unsigned(va_list ap, t_spe *elem)
{
	char				*conv;
	char				c;
	unsigned long long	n;

	conv = elem->conv;
	c = elem->specifier;
	if (!strcmp(conv, "hh"))
		n = (unsigned char)va_arg(ap, int);
	else if (!strcmp(conv, "h"))
		n = (unsigned short int)va_arg(ap, int);
	else if (!strcmp(conv, "l"))
		n = va_arg(ap, unsigned long);
	else if (!strcmp(conv, "ll") || c == 'p')
		n = va_arg(ap, unsigned long long);
	else if (!conv[0])
		n = va_arg(ap, unsigned int);
	else
		return (-1);
	elem->s = (unsigned char *)create_str(c, &n);
	return (1);
}

static int	handle_int(va_list ap, t_spe *elem)
{
	char		*conv;
	char		c;
	long long	n;

	conv = elem->conv;
	c = elem->specifier;
	if (!strcmp(conv, "hh"))
		n = (char)va_arg(ap, int);
	else if (!strcmp(conv, "h"))
		n = (short int)va_arg(ap, int);
	else if (!strcmp(conv, "l"))
		n = va_arg(ap, long);
	else if (!strcmp(conv, "ll"))
		n = va_arg(ap, long long);
	else if (!conv[0])
		n = va_arg(ap, int);
	else
		return (-1);
	elem->s = (unsigned char *)create_str(c, &n);
	return (1);
}

static int	handle_char(va_list ap, t_spe *elem)
{
	char	*conv;
	char	c;

	c = elem->specifier;
	conv = elem->conv;
	if (c == 'c' && !conv[0])
		elem->s = ft_getwchar((char)va_arg(ap, int));
	else if (c == 's' && !conv)
		elem->s = (unsigned char *)va_arg(ap, char *);
	else if (c == 'C' || (c == 'c' && !strcmp(conv, "l")))
		elem->s = ft_getwchar(va_arg(ap, wchar_t));
	else if (c == 'S' || (c == 's' && !strcmp(conv, "l")))
		elem->s = ft_getwstr(va_arg(ap, wchar_t *));
	if (!elem->s)
		return (-1);
	return (1);
}

int			parser_getstr(va_list ap, t_spe *elem)
{
	char				c;

	c = elem->specifier;
	if (c == 'd' || c == 'D' || c == 'i')
	{
		if (handle_int(ap, elem) == -1)
			return (-1);
	}
	else if (c == 'x' || c == 'X' || c == 'u' || c == 'U' || c == 'o'||
			c == 'O' || c == 'p')
	{
		if (handle_unsigned(ap, elem) == -1)
			return (-1);
	}
	else if (c == 's' || c == 'S' || c == 'c' || c == 'C')
	{
		if (handle_char(ap, elem) == -1)
			return(-1);
	}
	else
		return (-1);
	return (1);
}
