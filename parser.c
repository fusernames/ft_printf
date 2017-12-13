/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:38:37 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/11 19:40:35 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(int c)
{
	return (c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'o' ||
			c == 'X' || c == 'x' || c == 'f' || c == 'p' ||
			c == 'c' || c == 's' || c == 'S' || c == 'C');
}

static int		is_flag(int c)
{
	return (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0');
}


static int		new_elem(const char *format, t_spe **start, va_list *ap)
{
	t_spe	*elem;
	t_spe	*last;
	int		i;

	i = 0;
	elem = *start;
	while (elem)
	{
		if (elem->next == NULL)
			last = elem;
		elem = elem->next;
	}
	if (!(elem = init_elem()))
		return (-1);
	while(is_flag(*format))
	{
		if (*format == ' ')
			elem->space = 1;
		else if (*format == '-')
			elem->less = 1;
		else if (*format == '+')
			elem->plus = 1;
		else if (*format == '#')
			elem->hash = 1;
		else if (*format == '0')
			elem->zero = 1;
		format++;
	}
	if (ft_isdigit(*format))
	{
		elem->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else if(*format == '*')
	{
		elem->width = va_arg(*ap, long long);
		format++;
	}
	if (*format == '.')
	{
		format++;
		if (ft_isdigit(*format))
		{
			elem->precision = atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		else if(*format == '*')
		{
			elem->precision = va_arg(*ap, long long);
			format++;
		}
	}
	while (isdigit(*format))
		format++;
	while (ft_isalpha(*format) && !is_specifier(*format))
	{
		if (i == 2)
		{
			free(elem);
			return (-1);
		}
		elem->conv[i++] = *format;
		format++;
	}
	elem->conv[i] = '\0';
	if (is_specifier(*format))
		elem->specifier = *format;
	else
		return (-1);
	if (*start == NULL)
		*start = elem;
	else
		last->next = elem;
	if (parser_getstr(*ap, elem) == -1)
		return (-1);
	return (1);
}

int			parser(const char *format, t_spe **start, va_list *ap)
{
	int		i;

	i = 0;
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			if (new_elem(&format[i + 1], start, ap) == -1)
				return (-1);
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		i++;
	}
	return (1);
}
