/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:55:20 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/11 00:47:03 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t length)
{
	char		*dest;
	const char	*str;
	int			c;

	c = 0;
	dest = dst;
	str = src;
	while (length)
	{
		dest[c] = str[c];
		c++;
		length--;
	}
	return (dest);
}
