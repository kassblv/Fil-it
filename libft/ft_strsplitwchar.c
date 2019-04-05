/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemora <pemora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:58:18 by pemora            #+#    #+#             */
/*   Updated: 2018/11/23 00:48:26 by pemora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s && *s != c)
			if (*(s + 1) == c || !(*(s + 1)))
				i++;
		s++;
	}
	return (i);
}

static int	count_letters(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s != c)
		{
			i++;
			s++;
		}
		if (*s == c)
			return (i);
		s++;
	}
	return (i);
}

static char	**free_split(char **split, int stop)
{
	int	i;

	i = 0;
	while (i < stop)
	{
		ft_strdel(split + i);
		i++;
	}
	free(split);
	return (NULL);
}

char		**ft_strsplitwchar(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	if (!(split = (char**)ft_memalloc(sizeof(char*) * count_words(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			j = count_letters(s, c);
			if (!(*(split + i) = ft_strsub(s, 0, j + 1)))
				return (free_split(split, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	*(split + i) = NULL;
	return (split);
}
