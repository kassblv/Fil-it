/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:39:49 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 11:39:52 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char ct;
	char *t;

	t = NULL;
	ct = (char)c;
	while (*str)
	{
		if (*str == ct)
			t = (char*)str;
		str++;
	}
	if (*str == ct)
		return ((char*)str);
	else
		return (t);
}
