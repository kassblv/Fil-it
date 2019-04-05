/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:40:01 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 12:09:13 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *dt;
	char *str;

	dt = dest;
	str = (char*)src;
	while (n)
	{
		(*dt++) = (*str);
		if ((*str++) == (char)c)
			return (dt);
		n--;
	}
	return (NULL);
}
