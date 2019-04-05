/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:12:20 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/11 11:53:44 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *des;
	char *str;

	des = (char*)dest;
	str = (char*)src;
	if (des > str)
	{
		des = des + n - 1;
		str = str + n - 1;
		while (n > 0)
		{
			*des-- = *str--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*des++ = *str++;
			n--;
		}
	}
	return (dest);
}
