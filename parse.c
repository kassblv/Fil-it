/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 03:53:58 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/27 08:04:48 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

static int		valid_format(char **block)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = -1;
	j = -1;
	while (block[++i])
	{
		while (block[i][++j])
		{
			if ((block[i][j] != '#' && block[i][j] != '.'
				&& block[i][j] != '\n') || (j == 4 && block[i][j] != '\n'))
				return (0);
			if (block[i][j] == '#')
				n++;
		}
		if (i > 4 || (j != 5 && j != 1))
			return (0);
		j = -1;
	}
	return (n != 4 ? 0 : 1);
}

static int		countlinks(char **block, int x, int y)
{
	int count;

	count = 0;
	if (x < 3 && block[y][x + 1] == '#')
		count++;
	if (x > 0 && block[y][x - 1] == '#')
		count++;
	if (y < 3 && block[y + 1][x] == '#')
		count++;
	if (y > 0 && block[y - 1][x] == '#')
		count++;
	return (count);
}

int				checkblock(char **block)
{
	int x;
	int y;
	int count;

	if (!(valid_format(block)))
		return (0);
	count = 0;
	x = 0;
	y = 0;
	while (block[y])
	{
		while (block[y][x])
		{
			if (block[y][x] == '#')
				count += countlinks(block, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	if (count != 8 && count != 6)
		return (0);
	return (1);
}
