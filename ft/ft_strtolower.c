/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:11:33 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/06 19:01:50 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtolower(char *str)
{
	char *ret;

	ret = str;
	while(*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}	
	return (ret);
}