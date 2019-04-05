/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 00:33:02 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/27 08:00:13 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H
# include "libft/get_next_line.h"
# include <fcntl.h>

typedef struct			s_tetris
{
	char				**tetris;
	int					height;
	int					width;
	struct s_tetris		*next;
}						t_tetris;

typedef struct			s_map
{
	char				**map;
	int					size;
	struct s_map		*foo;
}						t_map;

typedef struct			s_l
{
	int					maxx;
	int					maxy;
	int					x;
	int					y;
}						t_l;

int						fill_it(t_tetris *pieces);
int						checkblock(char **block);
t_tetris				*fill_pieces(int fd);
t_tetris				*set_limit(t_tetris *tab);
t_map					*newmap(t_tetris *pieces, int size);
void					free_piece(t_tetris *pieces);
void					free_tab(char **tab);
#endif
