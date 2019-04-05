/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 05:53:27 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/18 06:00:00 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_free(char *dest, char *src, size_t n)
{
	char *tab;

	tab = ft_strncpy(dest, src, n);
	free(src);
	return (tab);
}
