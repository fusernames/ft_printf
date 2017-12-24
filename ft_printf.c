/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:24:10 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/24 15:47:06 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print_str(char *fmt, t_spe *elem)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (fmt[i])
	{
		if (elem && elem->error)
			return (-1);
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			check_exceptions(elem);
			while (!is_specifier(fmt[i]) && fmt[i + 1])
				i++;
			i++;
			ret += print_specifier(elem);
			elem = elem->next;
		}
		else if (fmt[i] == '%' && fmt[i + 1] == '%')
		{
			ret += ft_putchar(fmt[i++]);
			i++;
		}
		else if (fmt[i])
			ret += ft_putchar(fmt[i++]);
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	t_spe	*start;
	va_list	ap;
	int		ret;

	start = NULL;
	va_start(ap, format);
	if (parser((char *)format, &ap, &start) == -1)
	{
		lst_del(start);
		return (-1);
	}
	ret = print_str((char *)format, start);
	va_end(ap);
	lst_del(start);
	return (ret);
}
