/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 08:37:29 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 12:27:58 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	swap;
	int		j;
	int		c;

	j = 0;
	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	c--;
	while (c > j)
	{
		swap = str[c];
		str[c] = str[j];
		str[j] = swap;
		c--;
		j++;
	}
	return (str);
}
