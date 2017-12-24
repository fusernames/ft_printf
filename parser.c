/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:38:37 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/24 15:45:18 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	parse_flags(char **fmt, t_spe *e)
{
	while (is_flag(**fmt))
	{
		if (**fmt == ' ')
			e->space = 1;
		else if (**fmt == '-')
			e->minus = 1;
		else if (**fmt == '+')
			e->plus = 1;
		else if (**fmt == '#')
			e->hash = 1;
		else if (**fmt == '0')
			e->zero = 1;
		(*fmt)++;
	}
}

static void	parse_width(char **fmt, t_spe *e, va_list *ap)
{
	if (ft_isdigit(**fmt))
	{
		e->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (**fmt == '*')
	{
		if ((e->width = va_arg(*ap, int)) < 0)
			e->width = 0;
		(*fmt)++;
	}
}

static void	parse_precision(char **fmt, t_spe *e, va_list *ap)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		e->precision = 0;
		if (ft_isdigit(**fmt))
		{
			e->precision = atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
		else if (**fmt == '*')
		{
			if ((e->precision = va_arg(*ap, int)) < -1)
				e->precision = -1;
			(*fmt)++;
		}
	}
}

static int	parse_spe(char **fmt, t_spe *e)
{
	int	i;

	i = 0;
	while (**fmt && ft_isalpha(**fmt) && !is_specifier(**fmt))
	{
		if (i == 2)
			return (0);
		e->conv[i++] = **fmt;
		(*fmt)++;
	}
	e->conv[i] = '\0';
	if (is_specifier(**fmt))
		e->spe = **fmt;
	else
		return (0);
	return (1);
}

int			parser(char *fmt, va_list *ap, t_spe **start)
{
	t_spe	*elem;
	t_spe	*last;

	elem = *start;
	while (*fmt)
	{
		if (*fmt == '%' && fmt[1] != '%')
		{
			fmt++;
			if (!(elem = init_elem()))
				return (-1);
			if (*start == NULL)
				*start = elem;
			else
				last->next = elem;
			parse_flags(&fmt, elem);
			parse_width(&fmt, elem, ap);
			parse_precision(&fmt, elem, ap);
			if (!parse_spe(&fmt, elem))
				return (-1);
			parse_str(elem, *ap);
			last = elem;
		}
		else if (*fmt == '%' && fmt[1] == '%')
			fmt++;
		fmt++;
	}
	return (1);
}
