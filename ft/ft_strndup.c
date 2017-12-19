/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:14:18 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/11 17:26:05 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	int	i;

	i = 0;
	if (s == NULL && (n < 6 && n != -1))
		n = 0;
	else if (s == NULL)
	{
		dup = malloc(7);
		ft_strcpy(dup, "(null)");
		return (dup);
	}
	else if (n == -1)
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
