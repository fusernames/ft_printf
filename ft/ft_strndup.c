/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:14:18 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/22 21:48:14 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (n < 0)
		n = ft_strlen(s);
	if ((dup = malloc(n + 1)) == NULL)
		return (NULL);
	while (s && s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
