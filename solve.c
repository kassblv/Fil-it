/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:03:06 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/27 08:04:55 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

static int		fits(t_tetris *piece, char **map, int col, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (piece->tetris[i])
	{
		while (piece->tetris[i][j] && piece->tetris[i][j] != '\n')
		{
			if (piece->tetris[i][j] != '.' && map[row + i][col + j] != '.')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int		place_piece(t_tetris *piece, char **map, int col, int row)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!(fits(piece, map, col, row)))
		return (0);
	while (piece->tetris[++i])
	{
		while (piece->tetris[i][++j] && piece->tetris[i][j] != '\n')
		{
			if (piece->tetris[i][j] != '.')
				map[row + i][col + j] = piece->tetris[i][j];
		}
		j = -1;
	}
	return (1);
}

static void		remove_piece(char **piece, char **map)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (piece[0][++i])
	{
		if (piece[0][i] != '.')
			break ;
	}
	c = piece[0][i];
	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			if (map[i][j] == c)
				map[i][j] = '.';
		j = -1;
	}
}

static int		solve(t_tetris *piece, t_map *board, int col, int row)
{
	if (!piece)
		return (1);
	while (board->map[row] && ((board->size - row) >= piece->height))
	{
		while (board->map[row][col] && ((board->size - col) >= piece->width))
		{
			if (place_piece(piece, board->map, col, row))
			{
				if ((col + 1) <= board->size)
				{
					if (solve(piece->next, board, 0, 0))
						return (1);
				}
				else if ((row + 1) <= board->size)
					if (solve(piece->next, board, 0, 0))
						return (1);
				remove_piece(piece->tetris, board->map);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (0);
}

int				fill_it(t_tetris *pieces)
{
	t_map	*board;
	int		size;
	int		i;

	size = 0;
	if (!(board = newmap(pieces, 0)))
		return (-1);
	while (!solve(pieces, board, 0, 0))
	{
		size++;
		if (!(board = newmap(pieces, size)))
			return (-1);
	}
	i = -1;
	while (board->map[++i])
		ft_putendl(board->map[i]);
	free_tab(board->map);
	free(board->map);
	free(board);
	free_piece(pieces);
	return (0);
}
