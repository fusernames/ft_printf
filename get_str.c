/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:12:25 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/07 01:04:56 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(char c, void *n)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (itoa_base(*((long long*)n), 10));
	if (c == 'X')
		return (itoa_base(*(( unsigned long long*)n), 16));
	if (c == 'x' || c == 'p')
		return (ft_strtolower(itoa_base(*((unsigned long long*)n), 16)));
	if (c == 'o' || c == 'O')
		return (itoa_base(*((unsigned long long*)n), 8));
	if (c == 'u' || c == 'U')
		return (ft_itoa_base_unsigned(*(long long unsigned*)n), 10);
	return (NULL);
}

int			get_str(va_list ap, t_spe *start)
{
	char				*conv;
	char				c;
	unsigned long long	un;
	long long			in;

	while (start)
	{
		c = start->specifier;
		conv = start->conv;
		if (c == 'd' || c == 'D' || c == 'i')
		{
			if (!conv[0] && c != 'p')
				in = va_arg(ap, int);
			else if (!strcmp(conv, "hh"))
				in = (char)va_arg(ap, int);
			else if (!strcmp(conv, "h"))
				in = (short int)va_arg(ap, int);
			else if (!strcmp(conv, "l"))
				in = va_arg(ap, long);
			else if (!strcmp(conv, "ll") || c == 'p')
				in = va_arg(ap, long long);
			start->s = create_str(c, &in);
		}
		else if (c == 's')
			start->s = va_arg(ap, char*);
		else
		{
			if (!conv[0])
				un = va_arg(ap, unsigned int);
			else if (!strcmp(conv, "hh"))
				un = (unsigned char)va_arg(ap, int);
			else if (!strcmp(conv, "h"))
				un = (unsigned short int)va_arg(ap, int);
			else if (!strcmp(conv, "l"))
				un = va_arg(ap, unsigned long);
			else if (!strcmp(conv, "ll"))
				un = va_arg(ap, unsigned long long);
			start->s = ft_itoa_base_unsigned(un, 10);
		}
		if (start->s == NULL)
			return (-1);
		start = start->next;
	}
	return (1);
}

/*void	get_str(va_list ap, t_c *start)
{
	char *s;
	while (start)
	{
		c = start->specifier;
		if (!ft_strcmp(s, "s"))
			start->c = va_arg(ap, char*);
		else if (!ft_strcmp(s, "d"))
			start->c = itoa_base(va_arg(ap, long), 10);
		else if (!ft_strcmp(s, "ld"))
			start->c = itoa_base(va_arg(ap, long), 10);
		else if (!ft_strcmp(s, "X"))
			start->c = itoa_base(va_arg(ap, int), 16);
		else if (!ft_strcmp(s, "x"))
			start->c = ft_strtolower(itoa_base(va_arg(ap, int), 16));
		else if (!ft_strcmp(s, "p"))
			start->c = ft_strtolower(itoa_base(va_arg(ap, long), 16));
		else
			start->c = itoa_base(va_arg(ap, int), 10);
		start = start->next;
	}
}*/
