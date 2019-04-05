/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:48:18 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 09:54:15 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *des;

	des = (unsigned char*)s;
	while (n > 0 && *des != (unsigned char)c)
	{
		des++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
		return (des);
}
