/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:40:32 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 11:21:33 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	if (s == NULL)
		return (NULL);
	tab = ft_strnew(len);
	if (tab == NULL)
		return (NULL);
	ft_strncpy(tab, s + start, len);
	tab[len] = '\0';
	return (tab);
}
