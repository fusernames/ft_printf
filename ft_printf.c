/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:24:10 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/11 19:43:58 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * 1. Parser les % dans une liste
 * 2. Checker les exceptions de la liste
 * 3. Remplir le champs *str de chaque element
 * 4. Produire la str finale
 */

static int	print_str(const char *format, t_spe *start)
{
	int		i;
	int		j;
	int		ret;
	char	c;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			j = 0;
			while (!is_specifier(format[i]) && format[i])
				i++;
			i++;
			c = start->specifier;
			while (start->s[j])
				write(1, &start->s[j++], 1);
			if (j == 0 && (c == 'c' || c == 'C'))
			{
				write(1, &start->s[j], 1);
				ret++;
			}
			ret += j;
			start = start->next;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			write(1, &format[i++], 1);
			ret++;
		}
		else if (format[i])
		{
			write(1, &format[i++], 1);
			ret++;
		}
	}
	return(ret);
}

int				ft_printf(const char *format, ...)
{
	t_spe	*start;
	va_list ap;
	int	ret;

	start = NULL;
	va_start(ap, format);
	if (parser(format, &start, &ap) == -1)
	{
		lst_del(start);
		return (-1);
	}
	check_exceptions(start);
	crave(start);
	ret = print_str(format, start);
	/*while (start)
	{
		printf("specifier\t-> %c\n", start->specifier);
		printf("conv\t\t-> %s\n", start->conv);
		printf("width\t\t-> %ld\n", start->width);
		printf("precision\t-> %ld\n", start->precision);
		printf("str\t\t-> %s\n", start->s);
		printf("\n");
		start = start->next;
	}*/
	va_end(ap);
	lst_del(start);
	return (ret);
}
