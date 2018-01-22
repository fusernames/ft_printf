/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:14:48 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/22 20:17:19 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_spe	*init_elem(t_spe **start, t_spe *elem)
{
	t_spe	*new;

	new = malloc(sizeof(t_spe));
	new->spe = '\0';
	new->conv[0] = '\0';
	new->zero = 0;
	new->hash = 0;
	new->space = 0;
	new->plus = 0;
	new->minus = 0;
	new->width = 0;
	new->precision = -1;
	new->error = 0;
	new->s = NULL;
	new->next = NULL;
	if (*start == NULL)
		*start = new;
	else
		elem->next = new;
	return (new);
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
