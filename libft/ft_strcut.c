/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 04:14:28 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/19 11:51:32 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *s1, size_t index, size_t length)
{
	char *str;

	str = ft_strnew(ft_strlen(s1) - length);
	ft_strncpy(str, s1, index);
	ft_strcat(str, s1 + index + length);
	free((char*)s1);
	return (str);
}
