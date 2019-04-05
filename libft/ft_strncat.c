/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 05:21:30 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/13 11:39:02 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t c;

	i = 0;
	c = 0;
	while (dest[c] != '\0')
		c++;
	while (n && src[i] != '\0')
	{
		dest[c + i] = src[i];
		i++;
		n--;
	}
	dest[c + i] = '\0';
	return (dest);
}
