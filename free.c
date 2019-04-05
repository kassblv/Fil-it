/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:14:47 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/27 08:00:17 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
}

void	free_piece(t_tetris *pieces)
{
	t_tetris *free_piece;

	if (!pieces)
		return ;
	while (pieces)
	{
		free_piece = pieces;
		pieces = pieces->next;
		free_tab(free_piece->tetris);
		free(free_piece);
	}
}
