/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:38:37 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/23 20:02:24 by alcaroff         ###   ########.fr       */
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
		{
			e->width = -(e->width);
			e->minus = 1;
		}
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
			e->precision = ft_atoi(*fmt);
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
	while (**fmt && is_conv(**fmt) && !is_specifier(**fmt))
	{
		if (i == 2)
			return (1);
		e->conv[i++] = **fmt;
		(*fmt)++;
	}
	e->conv[i] = '\0';
	e->spe = **fmt;
	if (!is_specifier(**fmt))
	{
		ft_bzero((e->s = malloc(2)), 2);
		e->s[0] = **fmt;
	}
	return (0);
}

int			parser(char *fmt, va_list *ap, t_spe **start)
{
	t_spe	*elem;

	elem = *start;
	while (*fmt)
	{
		if (*fmt == '%' && fmt[1] != '%')
		{
			fmt++;
			if (!(elem = init_elem(start, elem)))
				return (1);
			parse_flags(&fmt, elem);
			parse_width(&fmt, elem, ap);
			parse_precision(&fmt, elem, ap);
			parse_spe(&fmt, elem);
			parse_str(elem, *ap);
		}
		else if (*fmt == '%' && fmt[1] == '%')
			fmt++;
		fmt++;
	}
	return (0);
}
