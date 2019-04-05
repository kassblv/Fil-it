/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemora <pemora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:29:43 by pemora            #+#    #+#             */
/*   Updated: 2018/11/17 17:27:59 by pemora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && (*(s2 + i) && *(s1 + i)))
		i++;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
