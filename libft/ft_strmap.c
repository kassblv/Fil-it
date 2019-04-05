/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:18:48 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 09:59:19 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*tab;
	unsigned int	c;

	c = 0;
	if (s)
	{
		tab = ft_strnew(ft_strlen(s));
		if (tab == NULL)
			return (0);
		while (s[c] != '\0')
		{
			tab[c] = f(s[c]);
			c++;
		}
		return (tab);
	}
	return (NULL);
}
