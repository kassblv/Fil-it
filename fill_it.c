/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:38:36 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/27 08:00:08 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int		main(int ac, char **av)
{
	int			fd;
	t_tetris	*piece;

	if (ac != 2)
	{
		ft_putendl("fillit: wrong number of arguments");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	piece = fill_pieces(fd);
	if (!(piece))
		ft_putendl("error");
	else
		fill_it(piece);
	return (0);
}
