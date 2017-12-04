/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:38:37 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/04 23:23:33 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(int c)
{
	return (c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'o' ||
			c == 'X' || c == 'x' || c == 'f');
}

static int		is_flag(int c)
{
	return (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0');
}

static t_spe	*init_elem(void)
{
	t_spe	*elem;

	elem = malloc(sizeof(t_spe));
	elem->specifier[0] = '\0';
	elem->zero = 0;
	elem->hash = 0;
	elem->space = 0;
	elem->plus = 0;
	elem->less = 0;
	elem->width = 0;
	elem->precision = -1;
	elem->s = NULL;
	elem->next = NULL;

	return (elem);
}

static int		new_elem(const char *format, t_spe **start)
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
	elem = init_elem();
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
	if (isdigit(*format))
		elem->width = atoi(format);
	while (isdigit(*format))
		format++;
	if (*format == '.')
	{
		format++;
		elem->precision = atoi(format);
	}
	while (isdigit(*format))
		format++;
	while (ft_isalpha(*format) && !is_specifier(*format))
	{
		if (i == 2)
		{
			free(elem);
			return (0);
		}
		elem->specifier[i++] = *format;
		format++;
	}
	if (is_specifier(*format))
		elem->specifier[i++] = *format;
	else
	{
		free(elem);
		return (0);
	}
	elem->specifier[i] = '\0';
	if (*start == NULL)
		*start = elem;
	else
		last->next = elem;
	return (1);
}

int			parser(const char *format, t_spe **start)
{
	int		i;

	i = 0;
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			if (!new_elem(&format[i + 1], start))
				return (-1);
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		i++;
	}
	return (1);
}
