/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:10:30 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/11 19:28:07 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_spe	*init_elem(void)
{
	t_spe	*elem;

	elem = malloc(sizeof(t_spe));
	elem->spe = '\0';
	elem->conv[0] = '\0';
	elem->zero = 0;
	elem->hash = 0;
	elem->space = 0;
	elem->plus = 0;
	elem->minus = 0;
	elem->width = 0;
	elem->precision = -1;
	elem->error = 0;
	elem->s = NULL;
	elem->next = NULL;
	ft_bzero(elem->conv, 3);

	return (elem);
}

int		lst_del(t_spe *start)
{
	t_spe *tmp;
	while (start)
	{
		if (start->s)
			free(start->s);
		tmp = start;
		start = start->next;
		free(tmp);
	}
	return (1);
}
