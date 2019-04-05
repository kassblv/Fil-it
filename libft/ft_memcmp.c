/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:35:06 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 09:31:10 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (n > 0 && *s == *d)
	{
		s++;
		d++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s - *d);
}
