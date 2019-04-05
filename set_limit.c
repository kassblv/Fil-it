/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:41:43 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/27 08:00:04 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

static void		ft_set_limit(char **tab, t_l *l)
{
	int			last_tok;
	int			f_seen;
	int			i;
	int			j;

	f_seen = 0;
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#' && (last_tok = j) >= 0)
			{
				if ((!f_seen || l->x > j) && (l->x = j) >= 0)
					if ((!f_seen && (f_seen = 1))
							&& (l->y = i) >= 0)
						l->maxx = 0;
				l->maxy = i;
			}
			else if (tab[i][j] == '\n')
				if (l->maxx < last_tok)
					l->maxx = last_tok;
		}
	}
}

int				ft_space(t_l *l, char **new_str, t_tetris *tab)
{
	int i;

	i = l->y;
	while (i < l->maxy)
	{
		if (!(new_str[i - l->y] = (char*)malloc(l->maxx - l->x + 2)))
		{
			free(new_str);
			return (-1);
		}
		ft_strncpy(new_str[i - l->y], tab->tetris[i] + l->x, l->maxx - l->x);
		new_str[i - l->y][l->maxx - l->x] = '\n';
		new_str[i - l->y][(l->maxx - l->x) + 1] = '\0';
		++i;
	}
	return (0);
}

t_tetris		*set_limit(t_tetris *tab)
{
	char		**new_str;
	int			i;
	t_tetris	*copy;
	t_l			l;

	copy = tab;
	while (tab)
	{
		ft_set_limit(tab->tetris, &l);
		++l.maxy;
		++l.maxx;
		if (!(new_str = (char**)malloc(sizeof(*new_str)
						* (l.maxy - l.y + 2))))
			return (NULL);
		i = l.y;
		new_str[l.maxy - l.y] = (char*)ft_memset(ft_strnew(1), '\n', 1);
		new_str[l.maxy - l.y + 1] = 0;
		if (ft_space(&l, new_str, tab))
			return (NULL);
		free_tab(tab->tetris);
		free(tab->tetris);
		tab->tetris = new_str;
		tab = tab->next;
	}
	return (copy);
}
