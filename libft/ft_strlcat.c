/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:11:07 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/19 07:33:12 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;

	if ((len = ft_strlen(dst)) >= size)
		return (size + ft_strlen(src));
	ft_strncat(dst, src, size - len - 1);
	return (len + ft_strlen(src));
}
