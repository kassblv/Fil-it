/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemora <pemora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:04:22 by pemora            #+#    #+#             */
/*   Updated: 2018/11/27 07:50:25 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

static t_tetris	*new_piece(char **block)
{
	int			i;
	t_tetris	*new;

	i = -1;
	if (!(new = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	if (!(new->tetris = (char**)ft_memalloc(sizeof(char*) * 5)))
		return (NULL);
	while (++i < 4)
		if (!(new->tetris[i] = ft_strdup(block[i])))
			return (NULL);
	new->tetris[i] = NULL;
	new->next = NULL;
	return (new);
}

static t_tetris	*addnewpiece(t_tetris *pieces, char **block)
{
	t_tetris *head;

	if (!(checkblock(block)))
		return (NULL);
	if (!pieces)
		return (new_piece(block));
	head = pieces;
	while (head && head->next)
		head = head->next;
	if (!(head->next = new_piece(block)))
		return (NULL);
	return (pieces);
}

static t_tetris	*get_piece_size(t_tetris *pieces)
{
	int			i;
	t_tetris	*head;

	i = 0;
	head = pieces;
	while (pieces)
	{
		pieces->width = ft_strlen(pieces->tetris[0]) - 1;
		while (pieces->tetris[i])
			i++;
		pieces->height = i - 1;
		i = 0;
		pieces = pieces->next;
	}
	return (head);
}

static t_tetris	*set_chars(t_tetris *piece)
{
	t_tetris	*head;
	int			i;
	int			n;
	char		chr;

	i = -1;
	n = -1;
	chr = 'A' - 1;
	head = piece;
	while (head && ++chr)
	{
		while (head->tetris[++i])
		{
			while (head->tetris[i][++n])
				if (head->tetris[i][n] == '#')
					head->tetris[i][n] = chr;
			n = -1;
		}
		i = -1;
		head = head->next;
	}
	if (chr > 'Z')
		return (NULL);
	return (piece);
}

t_tetris		*fill_pieces(int fd)
{
	int			i;
	char		**block;
	char		*line;
	t_tetris	*pieces;

	i = 0;
	pieces = NULL;
	if (!(block = (char**)ft_memalloc(sizeof(char*) * 6)))
		return (NULL);
	block[5] = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 4 && (!(ft_strequ("", line))))
			return (NULL);
		block[i] = ft_strjoin_free(line, ft_strdup("\n"));
		if (i == 3 && (!(pieces = addnewpiece(pieces, block))))
			return (NULL);
		i == 4 ? (i = 0) : i++;
	}
	free_tab(block);
	free(block);
	if (i < 3)
		return (NULL);
	pieces = set_chars(get_piece_size(set_limit(pieces)));
	return (pieces);
}
