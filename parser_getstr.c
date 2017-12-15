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

#include "libftprintf.h"

static char	*create_str(char c, void *n)
{
	if (c == 'X')
		return (ft_itoa_base_un(*((unsigned long long*)n), 16));
	if (c == 'x' || c == 'p')
	{
		if (c == 'p' && *((unsigned long long*)n) == 0)
			return(ft_strdup("(nil)"));
		return (ft_strtolower(ft_itoa_base_un(*((unsigned long long*)n), 16)));
	}
	if (c == 'o' || c == 'O')
		return (ft_itoa_base_un(*((unsigned long long*)n), 8));
	if (c == 'u' || c == 'U')
		return (ft_itoa_base_un(*((unsigned long long*)n), 10));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_itoa_base(*((long long*)n), 10));
	return (NULL);
}

static int	handle_unsigned(va_list ap, t_spe *elem)
{
	char				*conv;
	char				c;
	unsigned long long	n;

	conv = elem->conv;
	c = elem->specifier;
	if (!ft_strcmp(conv, "hh"))
		n = (unsigned char)va_arg(ap, int);
	else if (!ft_strcmp(conv, "h"))
		n = (unsigned short int)va_arg(ap, int);
	else if (!ft_strcmp(conv, "l") || c == 'U')
		n = va_arg(ap, unsigned long);
	else if (!ft_strcmp(conv, "ll") || c == 'p')
		n = va_arg(ap, unsigned long long);
	else if (!ft_strcmp(conv, "j"))
		n = va_arg(ap, uintmax_t);
	else if (!ft_strcmp(conv, "z"))
		n = va_arg(ap, size_t);
	else if (!conv[0])
		n = va_arg(ap, unsigned int);
	else
		return (-1);
	elem->s = create_str(c, &n);
	return (1);
}

static int	handle_int(va_list ap, t_spe *elem)
{
	char		*conv;
	char		c;
	long long	n;

	conv = elem->conv;
	c = elem->specifier;
	if (!ft_strcmp(conv, "hh"))
		n = (char)va_arg(ap, int);
	else if (!ft_strcmp(conv, "h"))
		n = (short int)va_arg(ap, int);
	else if (!ft_strcmp(conv, "l") || c == 'D')
		n = va_arg(ap, long);
	else if (!ft_strcmp(conv, "ll"))
		n = va_arg(ap, long long);
	else if (!ft_strcmp(conv, "j"))
		n = va_arg(ap, intmax_t);
	else if (!ft_strcmp(conv, "z"))
		n = va_arg(ap, size_t);
	else if (!conv[0])
		n = va_arg(ap, int);
	else
		return (-1);
	elem->s = create_str(c, &n);
	return (1);
}

static int	handle_char(va_list ap, t_spe *elem)
{
	char	*conv;
	char	c;

	c = elem->specifier;
	conv = elem->conv;
	if (c == 'c' && !conv[0])
		elem->s = ft_getchar((char)va_arg(ap, int));
	else if (c == 's' && !conv[0])
	{
		if ((elem->s = ft_strdup(va_arg(ap, char *))) == NULL)
			elem->s = ft_strdup("(null)");
	}
	else if (c == 'C' || (c == 'c' && !ft_strcmp(conv, "l")))
	{
		if((elem->s = ft_getwchar(va_arg(ap, wchar_t))) == NULL)
			return (-1);
	}
	else if (c == 'S' || (c == 's' && !ft_strcmp(conv, "l")))
	{
		if((elem->s = ft_getwstr(va_arg(ap, wchar_t *))) == NULL)
			return (-1);
	}
	if (!elem->s)
		return (-1);
	return (1);
}

int			parser_getstr(va_list ap, t_spe *elem)
{
	char				c;

	c = elem->specifier;
	if (c == 'x' || c == 'X' || c == 'u' || c == 'U' || c == 'o'||
			c == 'O' || c == 'p')
	{
		if (handle_unsigned(ap, elem) == -1)
			return (-1);
	}
	else if (c == 'd' || c == 'D' || c == 'i')
	{
		if (handle_int(ap, elem) == -1)
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
