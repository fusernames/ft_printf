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

static int		print_str(const char *format, t_spe *start)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if (start->error)
				return (-1);
			while (!is_specifier(format[i]) && format[i])
				i++;
			i++;
			ret += print_specifier(start);
			start = start->next;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			ret += ft_putchar(format[i++]);
		}
		else if (format[i])
			ret += ft_putchar(format[i++]);
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
	/*while (start)
	{
		printf("\nspecifier\t-> %c\n", start->spe);
		printf("conv\t\t-> %s\n", start->conv);
		printf("+\t\t-> %d\n", start->plus);
		printf("width\t\t-> %ld\n", start->width);
		printf("precision\t-> %ld\n", start->precision);
		printf("str\t\t-> %s\n", start->s);
		printf("error\t\t-> %d\n", start->error);
		printf("\n");
		start = start->next;
	}*/
	check_exceptions(start);
	ret = print_str(format, start);
	va_end(ap);
	lst_del(start);
	return (ret);
}
